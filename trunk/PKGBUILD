# $Id$
# Maintainer: Sébastien Luttringer <seblu@aur.archlinux.org>

pkgbase=linux-tools
pkgname=('perf' 'cpupower')
pkgver=3.3
pkgrel=4
license=('GPL2')
arch=('i686' 'x86_64')
url='http://www.kernel.org'
options=('!strip')
makedepends=('asciidoc' 'xmlto')
# split packages need all package dependencies set manually in makedepends
makedepends+=('python2' 'libnewt' 'elfutils' 'pciutils')
source=("http://ftp.kernel.org/pub/linux/kernel/v3.0/linux-$pkgver.tar.xz"
        "http://ftp.kernel.org/pub/linux/kernel/v3.0/patch-$pkgver.4.xz"
        'cpupower.rc'
        'cpupower.conf'
        'cpupower.service')
md5sums=('7133f5a2086a7d7ef97abac610c094f5'
         '9c4cc16f10b645fbb90f6c05ad388883'
         '73dbc931e86b3b73d6e2338dcbee81a4'
         '857ccdd0598511e3bf4b63522754dc48'
         '20870541e88109d2f153be3c58a277f1')

build() {
  # apply stable patching set
  if [[ -e "$srcdir"/patch-* ]]; then
    msg2 'Applying stable patch set'
    patch -N -p1 -i "$srcdir"/patch-*
  fi

  msg2 'Build perf'
  cd linux-$pkgver/tools/perf
  make PYTHON=python2 DESTDIR="$pkgdir/usr" perfexecdir="lib/$pkgname" \
    PERF_VERSION=$pkgver-$pkgrel all man

  msg2 'Build cpupower'
  # we cannot use --as-needed
  LDFLAGS=${LDFLAGS:+"$LDFLAGS,--no-as-needed"}
  cd "$srcdir/linux-$pkgver/tools/power/cpupower"
  make VERSION=$pkgver-$pkgrel
}

package_perf() {
  pkgdesc='Linux kernel performance auditing tool'
  depends=('python2' 'libnewt' 'elfutils')

  cd linux-$pkgver/tools/perf
  make PYTHON=python2 DESTDIR="$pkgdir/usr" perfexecdir="lib/$pkgname" \
    PERF_VERSION=$pkgver install install-man
}

package_cpupower() {
  pkgdesc='Linux kernel tool to examine and tune power saving related features of your processor'
  backup=('etc/conf.d/cpupower')
  depends=('pciutils')
  conflicts=('cpufrequtils')

  cd linux-$pkgver/tools/power/cpupower
  make \
    DESTDIR="$pkgdir" \
    mandir='/usr/share/man' \
    docdir='/usr/share/doc/cpupower' \
    install install-man
  # install rc.d script
  cd "$srcdir"
  install -D -m 755 cpupower.rc "$pkgdir/etc/rc.d/cpupower"
  install -D -m 644 cpupower.conf "$pkgdir/etc/conf.d/cpupower"
  install -D -m 644 cpupower.service "$pkgdir/usr/lib/systemd/system/cpupower.service"

}

# vim:set ts=2 sw=2 ft=sh et:
