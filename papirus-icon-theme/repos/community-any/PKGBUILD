# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20230301
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("GPL3")
depends=('gtk-update-icon-cache')
source=("https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('bdb0bb4c16b33459c19665953294b34776d2ac712ee6f1e8673396f18673b68a10c90d3b2406febb5d4fad76296eb4f60f0db60a85bf6ee6f15700ee025d9cec')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
