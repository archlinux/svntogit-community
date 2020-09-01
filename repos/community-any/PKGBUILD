# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20200901
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('0c1abdf58aeaff6aa8bce2b1db541377633e15282024f757d949adc4cf3e73d08b66b5188fa31530394cb804e88881b5a66c4d80772469d606cfc192c076224e')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
