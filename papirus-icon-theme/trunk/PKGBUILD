# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20210401
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('317eed658897dd55d8393669cb62b2a8f9211120b8e132263c70ddd2f5710973c78230f37bd0f60c75b7b67912d7d2cff2d048dd7b29ffb9c68c73c2ab89ee2b')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
