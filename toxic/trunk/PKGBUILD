# Maintainer: Jiachen Yang <farseerfc@gmail.com>
# AUR Maintainer: Vlad M. <vlad@archlinux.net>

pkgname=toxic
pkgdesc='CLI Tox client'
license=('GPL3')
pkgver=0.10.0
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
sha512sums=('bfbe8e4c90b4fcbdbe7cc96cb402e4c2f1609e2970e51d6d2ad2c8596350ce96ac9f4d06fbb71350e56d8892e2ed4ee8c5adf4f66cdad6b152c959802bddc6cc'
            'SKIP')
validpgpkeys=('BABD00573A065BFA90D53D563627F3144076AE63')  # Jfreegman <jfreegman@gmail.com>

prepare() {
  cd "$pkgname-$pkgver"
}

build() {
  cd "$pkgname-$pkgver"
  # enabled X11 on konsole may cause https://github.com/JFreegman/toxic/issues/277
  # but we can only do video and call with X11 enabled https://bugs.archlinux.org/task/52836
  make PREFIX=/usr
}

package() {
  cd "$pkgname-$pkgver"
  make PREFIX=/usr DESTDIR="$pkgdir" install
}
