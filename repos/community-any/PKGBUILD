# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20220808
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("GPL3")
depends=('gtk-update-icon-cache')
source=("https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('4233ec11fad43901fca346bb3db94ec68466b91740b1a25c3eed5772a2ccef086500443af96373d19b172923f8dd8b6814859fe402d78f44b31ac7d555b598bd')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
