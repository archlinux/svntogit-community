# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20190302
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('ec210b6507b60d3be2c62b02f8ac99ed079ab20f6da381afc1898f726d0ce1df19d1bed5aa29d40c6fac1cae78e45c56562be6c5ad615766c9c5295ec1cf6142')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
