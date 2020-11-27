# Maintainer: Jiachen Yang <farseerfc@gmail.com>
# AUR Maintainer: Vlad M. <vlad@archlinux.net>

pkgname=toxic
pkgdesc='CLI Tox client'
license=('GPL3')
pkgver=0.9.1
pkgrel=1
depends=('curl'
         'desktop-file-utils'
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
sha512sums=('550c6fdca4fe7d56f4e4409a6ad0f2c89fd17c538f8ac48275a4656baf67466f178d9a2ed738292b3c11710474e0306d8c16deceed78cde2d2d48c813604bd6f'
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
