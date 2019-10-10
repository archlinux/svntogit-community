# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20191009
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('09d259783439721baf68bb5c65cc9cb51af148356e8c8c277ba2f45b5c96358f14defe1bb34db0281cb0cf77023ab54017e0d348de2910648a918a1638ae334f')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
