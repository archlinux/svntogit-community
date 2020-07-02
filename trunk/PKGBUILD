# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20200702
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('ff2aa30bb70361f2952be203b3e3d00aae248726b5413a3a8e9ad7d6e7d0759e9bfd156cc65520175aba0e5436e9e58453ae0058d7d639d5c9a818e7f158761c')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
