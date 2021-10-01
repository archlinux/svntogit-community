# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20211001
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("GPL3")
depends=('gtk-update-icon-cache')
source=("https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('f6816e5a24d2337e4cda84f66116e35ca24c5e5db81f0f7a10895fadf93a48c108df8182250bfa3da3fe0be26a8165c279e92a353053357c34745db845458424')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
