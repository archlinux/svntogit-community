# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20190817
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('82276c97a65e1259b15f1c2a193d3dc7b5398327de5609d7faf6a8d8a2adba41d3b3b9b6b15eadf846500fedbfd0853cc4c13a7feb4d93864507e160041b16b6')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
