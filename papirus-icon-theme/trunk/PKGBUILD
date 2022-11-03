# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20221101
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("GPL3")
depends=('gtk-update-icon-cache')
source=("https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('f1266cb5092b14c4f5ba94c2bfc6d53c14e71fe737d4d96661b11af33077d810c3c609524288249d310be5d8f18eb061eb13c53f637636ada70a9ac18493c9b3')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
