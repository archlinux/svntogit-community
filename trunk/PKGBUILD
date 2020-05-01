# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20200430
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('5be8e68f3b0bff32c8c1c8c6fc4d4358a1fa18b9395cefbde4b6056fd38d1fb68f2cc555b5aa98e0399c24ddeb119d501b00098c459d43a734ae831b7df9624c')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
