# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20201201
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('0dc643e869eb073aa1ec17b0502334579eecf6048f6d7d268d00c43d4981603a751cb5c9eda2d598b47f8c714c2dd03c0adaa30be66193b4676895c3af8846f8')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
