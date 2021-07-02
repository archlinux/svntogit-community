# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20210701
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('0ec131bac6a0804d0a61d0c01c30d8d55f4438e93e17849a5c3cb741c4d8aa050977b24101d7f33416a7d617b53c5dca28ce38316e52bd5f72d9034147983d4d')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
