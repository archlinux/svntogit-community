# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20190203
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('40e274b31cf3f78512229c68c9fc52efcf7f2cb36db4c474052fd954e31ad5ca4f2345df9cc26017056a0604cc1cc9ccd77b4b703d6020da1a8aede571a82926')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
