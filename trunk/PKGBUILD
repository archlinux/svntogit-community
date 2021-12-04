# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20211201
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("GPL3")
depends=('gtk-update-icon-cache')
source=("https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('746055e9db0ef11c996fd90892582ca5ffd3e7c77aa08a43de2dd162364e915c73b3e1ab139c8caa4295e0857b4b5a6e273606f41ae5ab91de9dd160598ec621')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
