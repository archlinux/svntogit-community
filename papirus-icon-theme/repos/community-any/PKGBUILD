# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20210901
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("GPL3")
depends=('gtk-update-icon-cache')
source=("https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('667c4ab3ac4cfc6732e995cc8908ea71e44cbdbc5975bc6a50a889cc59c1ba07fda7b8ec78b6e60cd21aaec2e2c61884d5a59dfd7451710c91c13614847e8a7c')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
