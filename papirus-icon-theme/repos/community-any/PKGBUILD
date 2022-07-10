# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20220710
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("GPL3")
depends=('gtk-update-icon-cache')
source=("https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('2b9a51447e822e92d1660342de6f75ec57a641a152f4e7dd119422a1f98fe625adcf178814db8f0caf6156a17c73824c340dc59ada3523e44917f4d86db36098')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
