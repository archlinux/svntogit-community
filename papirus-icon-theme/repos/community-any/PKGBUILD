# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20190802
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('880681502d0b405e8a7962d6978d0a6cac3aec386723b69655d97157f8c5140fc88b711d7983e91b2900841e420af73a58f3ecb13f5e6122cd754a6ca26d84db')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
