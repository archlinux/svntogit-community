# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Mike Swanson <mikeonthecomputer@gmail.com>

pkgname=pps-tools
pkgdesc="LinuxPPS user-space tools"
pkgver=1.0.3
pkgrel=1
arch=('x86_64')
url="http://linuxpps.org/"
license=('GPL2')
depends=('bash')
source=("https://github.com/ago/pps-tools/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
b2sums=('a57be9e7e3c9969a6bfd91bbdd618ab875c9c92cad3a2206653f2719896cf293e87ca941484d60d9af22ae1a64daa10689621504edc652a31b2bf6af8741eb64')

build() {
  cd $pkgname-$pkgver
  LDLIBS=-lm make
}

package() {
  cd $pkgname-$pkgver
  install -dm755 "$pkgdir/usr/bin" "$pkgdir/usr/include/sys"
  LDLIBS=-lm make DESTDIR="$pkgdir/" install
}
