# Maintainer: Jiachen Yang <farseerfc@gmail.com>
# AUR Maintainer: Vlad M. <vlad@archlinux.net>

pkgname=toxic
pkgdesc='CLI Tox client'
license=('GPL3')
pkgver=0.8.1
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
sha512sums=('d63f5c4c853823db4c511e08901d6fcd581be29511a3ee04852fecd19709012b6cddee8e39e7a564bc8a2bc84a0a2455abe255bb20f65e06b26b35bcf90d9b76'
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
