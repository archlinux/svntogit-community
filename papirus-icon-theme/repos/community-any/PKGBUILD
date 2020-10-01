# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20201001
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('92e1b8449dc87945661df50eb00806960fdd7babfb3510e7b088ef4125ae0d90e873979ec6c5fadb20f2ab4d0ebc005865f6aecdf967a33864deda406e1dc897')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
