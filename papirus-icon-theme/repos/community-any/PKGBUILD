# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20190701
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('b5354cf6a6556e15c311f99d7b1cca45e1badf822b794afa4e69417e366cf5f5b01963fd48abe04b64846898bc04d15a17441c868c3ba5c5682458172c32800f')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
