# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20201031
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('72a79c384155135b2069372be7f310f012a0b72991a7f10d93ede7a7b3f73cc72b547114e6779d6279578b5c1e74f0d56969c18453b7e93e97fc994ae93a9833')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
