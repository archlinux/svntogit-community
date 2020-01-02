# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20200102
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('63e80ff061657bf6512d3906cae67d24221cdaea70002281fa91c4c8f127a504cac4e1a1afce0da9555ef917d30a390891c7f8d7f6c11064865819b88887a84f')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
