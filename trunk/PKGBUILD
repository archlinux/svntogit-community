# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20220204
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("GPL3")
depends=('gtk-update-icon-cache')
source=("https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('e85a9f3fa2564fb6404205695c9500baf54d37c7c03288d086c2bdff5b722d8eae8b283bab0658eebd1760e8bbe4bd1875958f68b065611cb761e4c2c08b1079')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
