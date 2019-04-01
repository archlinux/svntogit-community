# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20190331
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('fe2ba861afbc969251f8b3121cbb0d980cfed2901575a9b28cb344441623eda86e3db7947a65b2f6923610e0b04d7bdacaeebba8efcb2bf2e46575c527eafd13')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
