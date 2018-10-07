# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20181007
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('a3ebd06d8aa2afa52e7d37792e1393bc976be8ef9778390e520252ca3682125ddf8b1480b2871922e978b64818922ded70c575eea10b31e5b6d108be7e51b449')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
