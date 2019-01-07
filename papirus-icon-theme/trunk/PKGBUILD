# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20190106
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('ec9de316c13067e2928c3c9d501b6160c1aeb43dfef0e6a6ee55d3b194383634472bc54b40a662160051375487519346a63518c91f95872af6a16dee8e739b1d')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
