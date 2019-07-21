# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20190720
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('0092d02c609642f4c4440a74082dc973f5d26dd3d03461dec8e26af0d053609b04ad9cda45debbbdf11e7795b5a56b8016c7900f2f37412a28c2e0e37436bcef')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
