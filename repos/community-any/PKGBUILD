# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20181120
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('430290d78a6f564eaab7a7a3a7b8fbe33c9ad14f69915f29b063c77e9452a1885e14d58dc472f347ed07da3fdd995e72528b65c3334bb7ba0e940a3da6e3f7dd')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
