# $Id$
# Maintainer: Sébastien Luttringer <seblu@aur.archlinux.org>

pkgbase=linux-tools
pkgname=('perf' 'cpupower')
pkgver=3.2
kernver=${pkgver}.1
[[ ${kernver##*rc} != $kernver ]] && testing='testing'
pkgrel=1
license=('GPL2')
arch=('i686' 'x86_64')
url='http://www.kernel.org'
options=('!strip')
makedepends=('asciidoc' 'xmlto')
# split packages need all package dependencies set manually in makedepends
makedepends+=('python2' 'libnewt' 'elfutils' 'pciutils')
source=("http://ftp.kernel.org/pub/linux/kernel/v3.0/$testing/linux-$kernver.tar.xz"
        'cpupower.rc'
        'cpupower.conf'
        'cpupower.service') 
md5sums=('cd2f8b7752c85c337af809391f4afb94'
         '26af384ca282bc0dc38ff65acc7bb4b9'
         '857ccdd0598511e3bf4b63522754dc48'
         '20870541e88109d2f153be3c58a277f1')

build() {
  msg2 'Build perf'
  cd linux-$kernver/tools/perf
  make PYTHON=python2 DESTDIR="${pkgdir}/usr" perfexecdir="lib/$pkgname" \
    PERF_VERSION=$pkgver-$pkgrel all man

  msg2 'Build cpupower'
  # we cannot use --as-needed
  LDFLAGS=${LDFLAGS:+"$LDFLAGS,--no-as-needed"}
  cd "$srcdir/linux-$kernver/tools/power/cpupower"
  make VERSION=$pkgver-$pkgrel
}

package_perf() {
  pkgdesc='Linux kernel performance auditing tool'
  depends=('python2' 'libnewt' 'elfutils')

  cd linux-${kernver}/tools/perf
  make PYTHON=python2 DESTDIR="${pkgdir}/usr" perfexecdir="lib/$pkgname" \
    PERF_VERSION=$pkgver install install-man
}

package_cpupower() {
  pkgdesc='Linux kernel tool to examine and tune power saving related features of your processor'
  backup=('etc/conf.d/cpupower')
  depends=('pciutils')
  conflicts=('cpufrequtils')

  # install rc.d script
  install -D -m 755 cpupower.rc "$pkgdir/etc/rc.d/cpupower"
  install -D -m 644 cpupower.conf "$pkgdir/etc/conf.d/cpupower"
  install -D -m 644 cpupower.service "$pkgdir/lib/systemd/system/cpupower.service"

  cd linux-$kernver/tools/power/cpupower
  make \
    DESTDIR="$pkgdir" \
    INSTALL='/bin/install -c' \
    mandir='/usr/share/man' \
    docdir='/usr/share/doc/cpupower' \
    install install-man
}

# vim:set ts=2 sw=2 ft=sh et:
