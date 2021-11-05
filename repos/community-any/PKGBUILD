# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20211101
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("GPL3")
depends=('gtk-update-icon-cache')
source=("https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('13b8e0624d1cb0a39f5dbb407682766de942a31a19b683ca1429dc9c97b4f236e070176f1a5e6f37893d0587276d37c6b8e3cee2bea72bf535598ea84704f717')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
