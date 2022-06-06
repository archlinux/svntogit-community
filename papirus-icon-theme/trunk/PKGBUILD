# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20220606
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("GPL3")
depends=('gtk-update-icon-cache')
source=("https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('ccf786a478e5a97052f11999c8fc48bde4c677a036bad3cb3cb908b5cde1055565cdb2914d70dd52029c4c4cb2c60fb1da0daa6dfa076176b5a5aced1665d0c0')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
