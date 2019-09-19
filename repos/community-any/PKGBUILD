# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20190919
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('183765db87863f46d5036ea020ef5f4da5f74b6b519bdf9409f95e904209ba308abf46af29d5d8e86a1abe95e18975bd9114cfc929cd4620a9cef49e6a5c939b')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
