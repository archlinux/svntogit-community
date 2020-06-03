# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20200602
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('c860efd6ab863cbeb7b5f0d3afb7e652bbd9daca9c5028b0c466d1930f7bacba137fce40220f858b2cff0ef575d1c9eb979d7ba1c79481d7dccdbd6a273953c0')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
