# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20210201
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('8703dedefd37a796f265561d148bba4e56bef7a61705ffce2549d3d7e5dfbaedf24ddbb280a1a9c97cd06e58573a74e8b1644f371ddfd9adb6d6c0a6e890d343')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
