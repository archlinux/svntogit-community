# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20191201
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('2faeeea2f0b3efe9b2f18783d5e081199295e03bda021243460daa28bde701b6f0aefb0fa6ba196bc32f44e4af72b7efadedbc377a56b315c2d1c3519c7934a1')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
