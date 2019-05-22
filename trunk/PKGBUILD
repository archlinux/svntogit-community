# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20190521
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('d5c33ce976d426f8ebe250714a4a0fabe6c0202579b62d0444c3881dab80d468bd3f92632dd05b0aea570646fc330f5f3a67650482e2044c490622294e5c2adb')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
