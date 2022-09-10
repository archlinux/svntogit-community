# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20220910
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("GPL3")
depends=('gtk-update-icon-cache')
source=("https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('0a60e50409438bd25f3081f148761d50f3941da647f14a93bcb7bcd1e104044c65fb7d6758b30ddfe903dd6d17b9b0b044b29b742998c7293c5d6b7745aad7aa')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
