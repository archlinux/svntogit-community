# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20220302
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("GPL3")
depends=('gtk-update-icon-cache')
source=("https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('54793eb6b890931cc2e11c741b0144c485b8446673c8568eb95cf2a546d14d68bf8446d22953d63ee19c2ccd072dfa2d6443bb401a03e81c56c5776e4d30145d')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
