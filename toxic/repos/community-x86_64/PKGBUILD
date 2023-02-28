# Maintainer: Jiachen Yang <farseerfc@gmail.com>
# AUR Maintainer: Vlad M. <vlad@archlinux.net>

pkgname=toxic
pkgdesc='CLI Tox client'
license=('GPL3')
pkgver=0.11.3
pkgrel=3
depends=('curl'
         'freealut'
         'libnotify'
         'qrencode'
         'libx11'
         'toxcore')
arch=('x86_64')
url='https://github.com/JFreegman/toxic'
source=("$pkgname-$pkgver.tar.gz::https://github.com/JFreegman/$pkgname/releases/download/v$pkgver/$pkgname-$pkgver.tar.gz"
	"$pkgname-$pkgver.tar.gz.asc::https://github.com/JFreegman/$pkgname/releases/download/v$pkgver/$pkgname-$pkgver.tar.gz.asc"
	)
sha512sums=('a0ca010067a07ac10ab1ca3f4e46184cf0d99db2a1a719de2ef5fadde3754435bc5259107b9982c2914e10f6d2d732df9a86957d144479e8c6276fbf47f9620d'
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
