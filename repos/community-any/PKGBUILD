# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20190615
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('083f1afcc7e46a9688f96f584193cf07bcbe45f445feaee976b208a90e7758138fa0d77d355da73b241698ac2e0d1594613b57092d53294bd7e9cfa7b5ee1145')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
