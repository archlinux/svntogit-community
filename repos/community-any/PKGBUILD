# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20230104
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("GPL3")
depends=('gtk-update-icon-cache')
source=("https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('c07adc6258e9c0b37b250efae91825004b5b440304b9a901dbccec90fe683eee6871f5bf3205e79ee1bf44fe13ce5f014cbfc99b1bb6488e82bd6b0b8b730bfa')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
