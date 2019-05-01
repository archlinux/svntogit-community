# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20190501
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('f056bb234cac0d80a6253b9b01dc7f2b4a28f54161cd5484966554d862f02552a030b21cb1f876a10b6e6e4e0f565037ed10ebe1727f8a5bfae4226f354505fb')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
