# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20191101
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('abbf3c6b248abd6945e7397ea53fe92e645d74918f6fa6f54e3701e560d75e94ac75c2e9d01d5bed7c989af8e14ea9dff4dba018956aaff43291d45fc7ab9e4d')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
