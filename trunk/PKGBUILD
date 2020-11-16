# Maintainer: Sébastien Luttringer

pkgbase=linux-tools
pkgname=(
  'bpf'
  'cgroup_event_listener'
  'cpupower'
  'hyperv'
  'libtraceevent'
  'linux-tools-meta'
  'perf'
#  'python-perf'
  'tmon'
  'turbostat'
  'usbip'
  'x86_energy_perf_policy'
)
pkgver=5.9
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
makedepends+=('perl' 'python' 'slang' 'elfutils' 'libunwind' 'numactl' 'audit' 'gtk2')
# cpupower deps
makedepends+=('pciutils')
# usbip deps
makedepends+=('glib2' 'sysfsutils' 'udev')
# tmon deps
makedepends+=('ncurses')
# bpf deps
makedepends+=('python-docutils')
groups=("$pkgbase")
source=("git+https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git#tag=v${pkgver//_/-}"
        "https://cdn.kernel.org/pub/linux/kernel/v5.x/patch-$pkgver.1.xz"
        "$pkgname-$pkgver-perf-visibility.patch::https://github.com/torvalds/linux/commit/d0e7b0c71fbb.patch"
        'cpupower.default'
        'cpupower.systemd'
        'cpupower.service'
        'usbipd.service'
        'hv_fcopy_daemon.service'
        'hv_kvp_daemon.service'
        'hv_vss_daemon.service')
sha256sums=('SKIP'
            '7edb7b9d06b02f9b88d868c74ab618baf899c94edb19a73291f640dbea55c312'
            'f29c9f8fc2db88856f02738b4af36c16127e22e2fa5d06f2113784b741011d3c'
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
  echo ':: libtraceevent'
  pushd linux/tools/lib/traceevent
  make
  popd

  echo ':: perf'
  pushd linux/tools/perf
  make -f Makefile.perf \
    prefix=/usr \
    lib=lib/perf \
    perfexecdir=lib/perf \
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
}

package_linux-tools-meta() {
  pkgdesc='Linux kernel tools meta package'
  groups=()
  depends=(
    'bpf'
    'cgroup_event_listener'
    'cpupower'
    'hyperv'
    'libtraceevent'
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

package_libtraceevent() {
  pkgdesc='Linux kernel trace event library'
  depends=('glibc')

  cd linux/tools/lib/traceevent
  install -dm 755 "$pkgdir/usr/lib"
  install -m 644 libtraceevent.so "$pkgdir/usr/lib"
  ln -sf libtraceevent.so "$pkgdir/usr/lib/libtraceevent.so.1"
}

package_perf() {
  pkgdesc='Linux kernel performance auditing tool'
  depends=('glibc' 'perl' 'python' 'slang' 'elfutils' 'libunwind' 'binutils'
           'numactl' 'audit' 'coreutils' 'glib2' 'xz' 'zlib' 'libelf' 'bash')
  optdepends=('gtk2: support GTK2 browser for perf report')

  cd linux/tools/perf
  make -f Makefile.perf \
    prefix=/usr \
    lib=lib/perf \
    perfexecdir=lib/perf \
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
  depends=('glibc')

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
  depends=('glibc')

  cd linux/tools/bpf
  # skip runsqlower until disabled in build
  make -W runqslower_install install prefix=/usr DESTDIR="$pkgdir"
  # fix bpftool hard written path
  mv "$pkgdir"/usr/sbin/bpftool "$pkgdir"/usr/bin/bpftool
  rmdir "$pkgdir"/usr/sbin
  # install man pages
  make -C bpftool doc-install prefix=/usr/share DESTDIR="$pkgdir"
}

# vim:set ts=2 sw=2 et:
