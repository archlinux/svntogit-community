# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20220508
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("GPL3")
depends=('gtk-update-icon-cache')
source=("https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('f456119b7890bdab57d6dd40c6f7b6e8d1a1bcb4b0b3d61ab8feadba62d029cabf80bab88cf59b29e720f1967508ddd19cb9d4fec036b4078a24b037c5f19004')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
