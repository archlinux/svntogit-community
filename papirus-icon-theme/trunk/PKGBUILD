# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20221201
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("GPL3")
depends=('gtk-update-icon-cache')
source=("https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('2c4f73f3036a66efccbc6c19d6e571782f0d8549a4bcee55d85413f4960dc1941a15cdc667760d73d5e75211444d4c4b9814bdd6294037719dd5cfe03a2ad445')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
