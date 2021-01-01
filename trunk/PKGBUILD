# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20210101
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('5799ee00ee42974f8434d33e4ba59cda745687c1a8722202fe3faf45e06f4a37cfaacb676f634da7c6184f13534f6903590d7accc9ce71f5411aee282f7d54cc')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
