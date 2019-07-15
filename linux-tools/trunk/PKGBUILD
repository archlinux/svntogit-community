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
  'python-perf'
  'tmon'
  'turbostat'
  'usbip'
  'x86_energy_perf_policy'
)
pkgver=5.2
pkgrel=1
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
groups=("$pkgbase")
source=("git+https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git#tag=v${pkgver//_/-}"
        "https://cdn.kernel.org/pub/linux/kernel/v5.x/patch-$pkgver.1.xz"
        'cpupower.default'
        'cpupower.systemd'
        'cpupower.service'
        'usbipd.service')
md5sums=('SKIP'
         'a45be902d46625f7b554f17bab3686f0'
         '56883c159381ba89e50ab8ea65efec77'
         '34f5ecc19770a1abbcd0fd65bfd1f065'
         '86c4e419e4ba80835c330d49ba3f56ad'
         'bb35634f480325a78b943f7e10165e86')

prepare() {
  cd linux

  # apply patch from the source array (should be a pacman feature)
  local filename
  for filename in "${source[@]}"; do
    filename="${filename##*/}"
    if [[ "$filename" =~ \.patch$ ]]; then
      msg2 "Applying patch $filename"
      patch -p1 -N -i "$srcdir/$filename"
    elif [[ "$filename" =~ ^patch- ]]; then
      msg2 "Applying linux $filename"
      patch -p1 -N -i "$srcdir/${filename%.*}"
    fi
  done
}

build() {
  msg2 'libtraceevent'
  pushd linux/tools/lib/traceevent
  make
  popd

  msg2 'perf'
  pushd linux/tools/perf
  make -f Makefile.perf \
    prefix=/usr \
    lib=lib/perf \
    perfexecdir=lib/perf \
    NO_SDT=1 \
    PYTHON=python \
    PYTHON_CONFIG=python-config \
    PERF_VERSION=$pkgver-$pkgrel \
    DESTDIR="$pkgdir" \
    all man
  popd

  msg2 'cpupower'
  pushd linux/tools/power/cpupower
  make VERSION=$pkgver-$pkgrel
  popd

  msg2 'x86_energy_perf_policy'
  pushd linux/tools/power/x86/x86_energy_perf_policy
  make
  popd

  msg2 'usbip'
  pushd linux/tools/usb/usbip
  # Fix gcc compilation
  sed -i 's,-Wall -Werror -Wextra,,' configure.ac
  ./autogen.sh
  ./configure --prefix=/usr --sbindir=/usr/bin
  make
  popd

  msg2 'tmon'
  pushd linux/tools/thermal/tmon
  make
  popd

  msg2 'cgroup_event_listener'
  pushd linux/tools/cgroup
  make
  popd

  msg2 'turbostat'
  pushd linux/tools/power/x86/turbostat
  make
  popd

  msg2 'hv'
  pushd linux/tools/hv
  CFLAGS+=' -DKVP_SCRIPTS_PATH=/usr/lib/hyperv/kvp_scripts/' make
  popd

  msg2 'bpf'
  pushd linux/tools/bpf
  # doesn't compile when we don't first compile bpftool in its directory
  cd bpftool
  make
  cd ..
  make
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
    'python-perf'
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
    install install-man
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

package_python-perf(){
  pkgdesc='Linux kernel performance auditing tool (python bindings)'
  depends=('python')

  cd linux/tools/perf

  make install-python_ext PYTHON=python DESTDIR="$pkgdir"
}


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
  done
  install -dm755 "$pkgdir/usr/lib/hyperv/kvp_scripts"
}

package_bpf() {
  pkgdesc='BPF tools'
  depends=('glibc')

  cd linux/tools/bpf
  make install prefix=/usr DESTDIR="$pkgdir"
  # fix bpftool hard written path
  mv "$pkgdir"/usr/sbin/bpftool "$pkgdir"/usr/bin/bpftool
  rmdir "$pkgdir"/usr/sbin
}

# vim:set ts=2 sw=2 et:
