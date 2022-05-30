# Maintainer: Sébastien Luttringer

pkgbase=linux-tools
pkgname=(
  'bootconfig'
  'bpf'
  'cgroup_event_listener'
  'cpupower'
  'hyperv'
  'linux-tools-meta'
  'perf'
#  'python-perf'
  'tmon'
  'turbostat'
  'usbip'
  'x86_energy_perf_policy'
)
pkgver=5.17
pkgrel=2
license=('GPL2')
arch=('x86_64')
url='https://www.kernel.org'
options=('!strip')
makedepends=('git')
# split packages need all package dependencies set manually in makedepends
# kernel source deps
makedepends+=('asciidoc' 'xmlto')
# perf deps
makedepends+=('perl' 'python' 'slang' 'elfutils' 'libunwind' 'numactl' 'audit' 'zstd' 'libcap')
# cpupower deps
makedepends+=('pciutils')
# usbip deps
makedepends+=('glib2' 'sysfsutils' 'udev')
# tmon deps
makedepends+=('ncurses')
# bpf deps
makedepends+=('readline' 'zlib' 'libelf' 'libcap' 'python-docutils')
# turbostat deps
makedepends+=('libcap')
# bpftool
makedepends+=('llvm' 'clang')
groups=("$pkgbase")
source=("git+https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git#tag=v${pkgver//_/-}?signed"
#        "https://cdn.kernel.org/pub/linux/kernel/v5.x/patch-$pkgver.1.xz"
        'cpupower.default'
        'cpupower.systemd'
        'cpupower.service'
        'usbipd.service'
        'hv_fcopy_daemon.service'
        'hv_kvp_daemon.service'
        'hv_vss_daemon.service')
validpgpkeys=(
  'ABAF11C65A2970B130ABE3C479BE3E4300411886'  # Linus Torvalds
  '647F28654894E3BD457199BE38DBBDC86092693E'  # Greg Kroah-Hartman
)
sha256sums=('SKIP'
            '4fa509949d6863d001075fa3e8671eff2599c046d20c98bb4a70778595cd1c3f'
            'b692f4859ed3fd9831a058a450a84d8c409bf7e3e45aac1c2896a14bb83f3d7a'
            '42d2ec9f1d9cc255ee7945a27301478364ef482f5a6ddfc960189f03725ccec2'
            '2e187734d8aec58a3046d79883510d779aa93fb3ab20bd3132c1a607ebe5498f'
            '16855c197d2334f820cb190312a5a7fffe9165189db01344a957e582e39e17d8'
            'b1315cb77a35454e1af9172f821a52e2a0cb18561be05a340d21cf337b01ae61'
            '2d5e2f8d40b6f19bf2e1dead57ca105d72098fb0b418c09ff2e0cb91089710af')

prepare() {
  cd linux

  # apply patch from the source array (should be a pacman feature)
  local src
  for src in "${source[@]}"; do
    src="${src%%::*}"
    src="${src##*/}"
    src="${src%.xz}"
    [[ $src = *.patch || $src = patch-* ]] || continue
    echo ":: Applying patch $src"
    patch -p1 -N -i "$srcdir/$src"
  done
}

build() {
  echo ':: perf'
  pushd linux/tools/perf
  make -f Makefile.perf \
    prefix=/usr \
    lib=lib/perf \
    perfexecdir=lib/perf \
    EXTRA_CFLAGS=' -Wno-error=bad-function-cast -Wno-error=declaration-after-statement -Wno-error=switch-enum' \
    NO_SDT=1 \
    PYTHON=python \
    PYTHON_CONFIG=python-config \
    PERF_VERSION=$pkgver-$pkgrel \
    DESTDIR="$pkgdir"
  popd

  echo ':: cpupower'
  pushd linux/tools/power/cpupower
  make VERSION=$pkgver-$pkgrel
  popd

  echo ':: x86_energy_perf_policy'
  pushd linux/tools/power/x86/x86_energy_perf_policy
  make
  popd

  echo ':: usbip'
  pushd linux/tools/usb/usbip
  # Fix gcc compilation
  sed -i 's,-Wall -Werror -Wextra,-fcommon,' configure.ac
  ./autogen.sh
  ./configure --prefix=/usr --sbindir=/usr/bin
  make
  popd

  echo ':: tmon'
  pushd linux/tools/thermal/tmon
  make
  popd

  echo ':: cgroup_event_listener'
  pushd linux/tools/cgroup
  make
  popd

  echo ':: turbostat'
  pushd linux/tools/power/x86/turbostat
  make
  popd

  echo ':: hv'
  pushd linux/tools/hv
  CFLAGS+=' -DKVP_SCRIPTS_PATH=\"/usr/lib/hyperv/kvp_scripts/\"' make
  popd

  echo ':: bpf'
  pushd linux/tools/bpf
  # doesn't compile when we don't first compile bpftool in its own directory and
  # man pages require to be also launch from the subdirectory
  make -C bpftool all doc
  # runqslower, require kernel binary path to build, skip it
  make -W runqslower
  popd

  echo ':: bootconfig'
  pushd linux/tools/bootconfig
  make
  popd
}

package_linux-tools-meta() {
  pkgdesc='Linux kernel tools meta package'
  groups=()
  depends=(
    'bootconfig'
    'bpf'
    'cgroup_event_listener'
    'cpupower'
    'hyperv'
    'perf'
#    'python-perf'
    'tmon'
    'turbostat'
    'usbip'
    'x86_energy_perf_policy'
  )
  conflicts=(
    'acpidump'
  )
}

package_perf() {
  pkgdesc='Linux kernel performance auditing tool'
  depends=('glibc' 'perl' 'python' 'slang' 'elfutils' 'libunwind' 'binutils'
           'numactl' 'audit' 'coreutils' 'glib2' 'xz' 'zlib' 'libelf' 'bash'
           'zstd' 'libcap')

  cd linux/tools/perf
  make -f Makefile.perf \
    prefix=/usr \
    lib=lib/perf \
    perfexecdir=lib/perf \
    EXTRA_CFLAGS=' -Wno-error=bad-function-cast -Wno-error=declaration-after-statement -Wno-error=switch-enum' \
    NO_SDT=1 \
    PYTHON=python \
    PYTHON_CONFIG=python-config \
    PERF_VERSION=$pkgver-$pkgrel \
    DESTDIR="$pkgdir" \
    install
  cd "$pkgdir"
  # add linker search path
  mkdir "$pkgdir/etc/ld.so.conf.d"
  echo '/usr/lib/perf' > "$pkgdir/etc/ld.so.conf.d/$pkgname.conf"
  # move completion in new directory
  install -Dm644 etc/bash_completion.d/perf usr/share/bash-completion/completions/perf
  rm -r etc/bash_completion.d
  # no exec on usr/share
  find usr/share -type f -exec chmod a-x {} \;
}

#package_python-perf(){
#  pkgdesc='Linux kernel performance auditing tool (python bindings)'
#  depends=('python')
#
#  cd linux/tools/perf
#
#  make install-python_ext PYTHON=python DESTDIR="$pkgdir"
#}


package_cpupower() {
  pkgdesc='Linux kernel tool to examine and tune power saving related features of your processor'
  backup=('etc/default/cpupower')
  depends=('glibc' 'bash' 'pciutils')
  conflicts=('cpufrequtils')
  replaces=('cpufrequtils')
  install=cpupower.install

  pushd linux/tools/power/cpupower
  make \
    DESTDIR="$pkgdir" \
    sbindir='/usr/bin' \
    libdir='/usr/lib' \
    mandir='/usr/share/man' \
    docdir='/usr/share/doc/cpupower' \
    install install-man
  popd
  # install startup scripts
  install -Dm 644 $pkgname.default "$pkgdir/etc/default/$pkgname"
  install -Dm 644 $pkgname.service "$pkgdir/usr/lib/systemd/system/$pkgname.service"
  install -Dm 755 $pkgname.systemd "$pkgdir/usr/lib/systemd/scripts/$pkgname"
}

package_x86_energy_perf_policy() {
  pkgdesc='Read or write MSR_IA32_ENERGY_PERF_BIAS'
  depends=('glibc')

  cd linux/tools/power/x86/x86_energy_perf_policy
  install -Dm 755 x86_energy_perf_policy "$pkgdir/usr/bin/x86_energy_perf_policy"
  install -Dm 644 x86_energy_perf_policy.8 "$pkgdir/usr/share/man/man8/x86_energy_perf_policy.8"
}

package_usbip() {
  pkgdesc='An USB device sharing system over IP network'
  depends=('glibc' 'glib2' 'sysfsutils' 'systemd-libs')

  pushd linux/tools/usb/usbip
  make install DESTDIR="$pkgdir"
  popd
  # module loading
  install -Dm 644 /dev/null "$pkgdir/usr/lib/modules-load.d/$pkgname.conf"
  printf 'usbip-core\nusbip-host\n' > "$pkgdir/usr/lib/modules-load.d/$pkgname.conf"
  # systemd
  install -Dm 644 usbipd.service "$pkgdir/usr/lib/systemd/system/usbipd.service"
}

package_tmon() {
  pkgdesc='Monitoring and Testing Tool for Linux kernel thermal subsystem'
  depends=('glibc' 'ncurses')

  cd linux/tools/thermal/tmon
  make install INSTALL_ROOT="$pkgdir"
}

package_cgroup_event_listener() {
  pkgdesc='Simple listener of cgroup events'
  depends=('glibc')

  cd linux/tools/cgroup
  install -Dm755 cgroup_event_listener "$pkgdir/usr/bin/cgroup_event_listener"
}

package_turbostat() {
  pkgdesc='Report processor frequency and idle statistics'
  depends=('glibc' 'libcap')

  cd linux/tools/power/x86/turbostat
  make install DESTDIR="$pkgdir"
}

package_hyperv() {
  pkgdesc='Hyper-V tools'
  depends=('glibc')

  cd linux/tools/hv
  for _p in hv_fcopy_daemon hv_kvp_daemon hv_vss_daemon; do
    install -Dm755 "$_p" "$pkgdir/usr/bin/$_p"
    install -Dm644 "$srcdir/$_p.service" "$pkgdir/usr/lib/systemd/system/$_p.service"
  done
  install -dm755 "$pkgdir/usr/lib/hyperv/kvp_scripts"
}

package_bpf() {
  pkgdesc='BPF tools'
  depends=('glibc' 'readline' 'zlib' 'libelf' 'libcap')

  cd linux/tools/bpf
  # skip runsqlower until disabled in build
  make -W runqslower_install install prefix=/usr DESTDIR="$pkgdir"
  # fix bpftool hard written path
  mv "$pkgdir"/usr/sbin/bpftool "$pkgdir"/usr/bin/bpftool
  rmdir "$pkgdir"/usr/sbin
  # install man pages
  make -C bpftool doc-install prefix=/usr/share DESTDIR="$pkgdir"
}

package_bootconfig() {
  pkgdesc='Apply, delete or show boot config to initrd'
  depends=('glibc')

  cd linux/tools/bootconfig
  install -dm755 "$pkgdir/usr/bin"
  make install DESTDIR="$pkgdir"
}

# vim:set ts=2 sw=2 et:
