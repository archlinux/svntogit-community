# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20200201
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('07ed45eb409ed12f57657f058f9a5a03dec77679ed598dc8645536a614ecc5424c60be57f10de20ca72204d2a21152fdd62adadf2637bbfa1266d588c787d7e9')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
