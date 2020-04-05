# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20200405
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('116aefea7049f7bdffee12fde8fa7088dfb4cd52f78bba617390700ba292b664dde32d30119f2929121988fa46244d452407b82f61f113b38810743c6db7e451')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
