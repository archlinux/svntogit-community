# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20200801
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('fd8262b4b56c825f145db466c7237f29322c76f8ec10c59a9cb97315b4a6ae3667c6e6e4910a8165529e762c5420298949f5b283ee4d37ac14135be35cdbf993')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
