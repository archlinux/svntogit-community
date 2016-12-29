# Maintainer: Jiachen Yang <farseerfc@gmail.com>
# AUR Maintainer: Vlad M. <vlad@archlinux.net>

pkgname=toxic
pkgdesc='CLI Tox client'
license=('GPL3')
pkgver=0.7.2
pkgrel=2
depends=('curl'
         'desktop-file-utils'
         'freealut'
         'libnotify'
         'qrencode'
         'toxcore')
arch=('i686' 'x86_64')
url='https://github.com/JFreegman/toxic'
source=("$pkgname-$pkgver.tar.gz::https://github.com/JFreegman/$pkgname/archive/v$pkgver/$pkgname-$pkgver.tar.gz"
	"$pkgname-$pkgver.tar.gz.asc::https://github.com/JFreegman/$pkgname/releases/download/v$pkgver/$pkgname-$pkgver.tar.gz.asc")
sha512sums=('cf3fd0afdc63aa4d2039e08a8f9f32a042a6412f0a242823205fcf058f56e732468389d4bdf614ded8b0d9704b05a315044ee216edd51546501a24be0b6d5b26'
            'SKIP')
validpgpkeys=('BABD00573A065BFA90D53D563627F3144076AE63')  # Jfreegman <jfreegman@gmail.com>

build() {
  cd "$pkgname-$pkgver"
  # disable X11 because https://github.com/JFreegman/toxic/issues/277
  make PREFIX=/usr DISABLE_X11=1
}

package() {
  cd "$pkgname-$pkgver"
  make PREFIX=/usr DESTDIR="$pkgdir" install
}
