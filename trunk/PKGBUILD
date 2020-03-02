# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20200301
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('8b9f0a9b0fdb676365d6b30af8ba8dee71ff433a4c4317151899f09614da3fc9764e5e9c48743cdf7c8fde6eea53a1d3ab37eb890f1486fc54ce328e6af9b348')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
