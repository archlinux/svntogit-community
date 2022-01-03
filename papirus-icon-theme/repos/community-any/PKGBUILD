# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20220101
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("GPL3")
depends=('gtk-update-icon-cache')
source=("https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('6f34dfe9fb6f89f1919dda6ee488095f765a2f1bdadbec90c5fb50910940a43a9668305e6ffb28884b8a9538cbf5cab93a9ca2115edbdbd00f1e601ced557167')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
