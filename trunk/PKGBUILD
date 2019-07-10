# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20190708
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('22c00aae09e4917fb83bdd2bc6e79f59c83bb6a6829d1085e5468d89f8639a01f3985132bae75b68a00ce44581970b045313a68f2f4786f91b24d94272faf650')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
