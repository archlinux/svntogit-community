# $Id$
# Maintainer: Sébastien Luttringer

pkgbase=linux-tools
pkgname=(
  'cgroup_event_listener'
  'cpupower'
  'libtraceevent'
  'linux-tools-meta'
  'perf'
  'tmon'
  'turbostat'
  'usbip'
  'x86_energy_perf_policy'
)
pkgver=4.5
pkgrel=3
license=('GPL2')
arch=('i686' 'x86_64')
url='http://www.kernel.org'
options=('!strip')
makedepends=('git')
# split packages need all package dependencies set manually in makedepends
# kernel source deps
makedepends+=('asciidoc' 'xmlto')
# perf deps
makedepends+=('perl' 'python2' 'libnewt' 'elfutils' 'libunwind' 'numactl' 'audit' 'gtk2')
# cpupower deps
makedepends+=('pciutils')
# usbip deps
makedepends+=('glib2' 'sysfsutils' 'udev')
# tmon deps
makedepends+=('ncurses')
groups=("$pkgbase")
source=("git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git#tag=v$pkgver"
        'cpupower.default'
        'cpupower.systemd'
        'cpupower.service'
        'usbipd.service'
        '02-archlinux-paths.patch'
        '04-fix-usip-h-path.patch')
md5sums=('SKIP'
         '56883c159381ba89e50ab8ea65efec77'
         '34f5ecc19770a1abbcd0fd65bfd1f065'
         '86c4e419e4ba80835c330d49ba3f56ad'
         'bb35634f480325a78b943f7e10165e86'
         '1bc4f8c7a21a30e1a873d07e69fb698b'
         'a73ea3ea6d9c9ecb1cc910871eead3ff')

prepare() {
  cd linux
  # apply patch from the source array (should be a pacman feature)
  local filename
  for filename in "${source[@]}"; do
    if [[ "$filename" =~ \.patch$ ]]; then
      msg2 "Applying patch $filename"
      patch -p1 -N -i "$srcdir/$filename"
    fi
  done
  :
}

build() {
  msg2 'libtraceevent'
  pushd linux/tools/lib/traceevent
  make
  popd

  msg2 'perf'
  pushd linux/tools/perf
  make \
    prefix=/usr \
    DESTDIR="$pkgdir" \
    WERROR=0 \
    PYTHON=python2 \
    PYTHON_CONFIG=python2-config \
    PERF_VERSION=$pkgver-$pkgrel \
    all man
  popd

  msg2 'cpupower'
  pushd linux/tools/power/cpupower
  # we cannot use --as-needed
  #LDFLAGS=${LDFLAGS:+"$LDFLAGS,--no-as-needed"}
  make VERSION=$pkgver-$pkgrel
  popd

  msg2 'x86_energy_perf_policy'
  pushd linux/tools/power/x86/x86_energy_perf_policy
  make
  popd

  msg2 'usbip'
  pushd linux/tools/usb/usbip
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
}

package_linux-tools-meta() {
  pkgdesc='Linux kernel tools meta package'
  groups=()
  depends=(
    'cgroup_event_listener'
    'cpupower'
    'libtraceevent'
    'perf'
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
  depends=('perl' 'python2' 'libnewt' 'elfutils' 'libunwind' 'binutils'
           'numactl' 'audit')
  optdepends=('gtk2: support GTK2 browser for perf report')

  cd linux/tools/perf
  make \
    prefix=/usr \
    DESTDIR="$pkgdir" \
    WERROR=0 \
    PYTHON=python2 \
    PYTHON_CONFIG=python2-config \
    PERF_VERSION=$pkgver-$pkgrel \
    install install-man
  cd "$pkgdir"
  # move completion in new directory
  install -Dm644 etc/bash_completion.d/perf usr/share/bash-completion/completions/perf
  rm -r etc
  # no exec on usr/share
  find usr/share -type f -exec chmod a-x {} \;
}

package_cpupower() {
  pkgdesc='Linux kernel tool to examine and tune power saving related features of your processor'
  backup=('etc/default/cpupower')
  depends=('bash' 'pciutils')
  conflicts=('cpufrequtils')
  replaces=('cpufrequtils')
  install=cpupower.install

  pushd linux/tools/power/cpupower
  make \
    DESTDIR="$pkgdir" \
    sbindir='/usr/bin' \
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
  depends=('glib2' 'sysfsutils' 'libsystemd')

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

# vim:set ts=2 sw=2 et:
