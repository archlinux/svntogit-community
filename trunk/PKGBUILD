# Maintainer: Antoine Damhet <antoine.damhet@lse.epita.fr>

pkgname=brightnessctl
pkgver=0.4
pkgrel=2
pkgdesc="Lightweight brightness control tool"
arch=('x86_64')
url='https://github.com/Hummer12007/brightnessctl'
license=('MIT')
source=(
  "$pkgname-$pkgver.tar.gz::https://github.com/Hummer12007/brightnessctl/archive/$pkgver.tar.gz"
)
sha512sums=('f0e1abe4dd7fc66a7990c0c42ecd9af079ba397fb0a49d339c5927fe639edbce4c30ecfcd16c3e0bf58de2eb4ca611dd1e1ce40eec9f95fe3960189c5e5396d8')
install='brightnessctl.install'

build() {
  cd $pkgname-$pkgver
  make
}

package() {
  cd $pkgname-$pkgver
  make UDEVDIR="/usr/lib/udev/rules.d" INSTALL_UDEV_RULES=1 DESTDIR="$pkgdir" install

  mkdir -p $pkgdir/usr/share/licenses/$pkgname
  install -m 0644 LICENSE $pkgdir/usr/share/licenses/$pkgname/
}

# vim:set ts=2 sw=2 et:
