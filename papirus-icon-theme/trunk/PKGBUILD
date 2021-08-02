# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20210802
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('b3cd1c65da452ed0f4a268874bf14183de3db8ac04557eb8fa02ea042127bcafa045bad5001b1c161b20659dc038233119703d0f851fc018e9d6cde841d2749d')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
