# Maintainer: Jiachen Yang <farseerfc@gmail.com>
# AUR Maintainer: Vlad M. <vlad@archlinux.net>

pkgname=toxic
pkgdesc='CLI Tox client'
license=('GPL3')
pkgver=0.11.1
pkgrel=1
depends=('curl'
         'freealut'
         'libnotify'
         'qrencode'
         'libx11'
         'toxcore')
arch=('x86_64')
url='https://github.com/JFreegman/toxic'
source=("$pkgname-$pkgver.tar.gz::https://github.com/JFreegman/$pkgname/archive/v$pkgver/$pkgname-$pkgver.tar.gz"
	"$pkgname-$pkgver.tar.gz.asc::https://github.com/JFreegman/$pkgname/releases/download/v$pkgver/$pkgname-$pkgver.tar.gz.asc"
	)
sha512sums=('53fba05271020547e779d63bea777f90f56b61e3eb2775afabe92e047a8347b4a9166628bb59d2eaab2e36a1121d791206ac68ff6604cb06fac6aaddbb05e787'
            'SKIP')
validpgpkeys=('BABD00573A065BFA90D53D563627F3144076AE63')  # Jfreegman <jfreegman@gmail.com>

prepare() {
  cd "$pkgname-$pkgver"
}

build() {
  cd "$pkgname-$pkgver"
  make PREFIX=/usr DISABLE_GAMES=1
}

package() {
  cd "$pkgname-$pkgver"
  make PREFIX=/usr DESTDIR="$pkgdir" install
}
