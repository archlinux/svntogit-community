# Maintainer: Jiachen Yang <farseerfc@gmail.com>
# AUR Maintainer: Vlad M. <vlad@archlinux.net>

pkgname=toxic
pkgdesc='CLI Tox client'
license=('GPL3')
pkgver=0.8.3
pkgrel=2
depends=('curl'
         'desktop-file-utils'
         'freealut'
         'libnotify'
         'qrencode'
         'toxcore')
arch=('x86_64')
url='https://github.com/JFreegman/toxic'
source=("$pkgname-$pkgver.tar.gz::https://github.com/JFreegman/$pkgname/archive/v$pkgver/$pkgname-$pkgver.tar.gz"
	"$pkgname-$pkgver.tar.gz.asc::https://github.com/JFreegman/$pkgname/releases/download/v$pkgver/$pkgname-$pkgver.tar.gz.asc"
	)
sha512sums=('c8d746efcc055592dd990dfa57415cc1eacaaa3b66303d7583d9f9e7e98b8829c8f1ae849f36a243c8896e99787dd2e493c92367de719b20a4a160bc7daea76e'
            'SKIP')
validpgpkeys=('BABD00573A065BFA90D53D563627F3144076AE63')  # Jfreegman <jfreegman@gmail.com>

prepare() {
  cd "$pkgname-$pkgver"
  #patch -Np1 < ../ver0.8.0.patch
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
