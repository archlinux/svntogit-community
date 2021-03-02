# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20210302
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('b8bba6a3f68b34da7f9e55ac19b37240d7dc0b1b7cb6523431d5e1ce08a90179e26beb621c8da4ff219d2c1e9ad390f8d0e6f413bc4296c15b1da872f09dfd26')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
