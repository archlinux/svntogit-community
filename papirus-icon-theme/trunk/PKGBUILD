# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20210501
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('65f096428756e52a4c373c206a320e2185fc176238100fd2e8dc9281c7772e3a3381a6ce2d4642be9ff0ea97f5e5292b1a5b631c07459d5863ee7e5cfcced8ac')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
