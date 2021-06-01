# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: kitsunyan <kitsunyan@inbox.ru>
# Contributor: Grigorii Horos <horosgrisa@gmail.com>

pkgname=papirus-icon-theme
pkgver=20210601
pkgrel=1
pkgdesc="Papirus icon theme"
arch=('any')
url="https://github.com/PapirusDevelopmentTeam/papirus-icon-theme"
license=("LGPL3")
depends=('gtk-update-icon-cache')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PapirusDevelopmentTeam/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('30b59e4f05718efb7790fa4e734d91886408adeb7e0adc9d98e7572ba5f4163fa81574ac8811b88106eebefd1b0dc71ffb4be07aac8f4720aa7b2a206a00150a')

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
