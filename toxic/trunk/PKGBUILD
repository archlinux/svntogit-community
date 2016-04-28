# Maintainer: Jiachen Yang <farseerfc@gmail.com>
# AUR Maintainer: Vlad M. <vlad@archlinux.net>

pkgname=toxic
pkgdesc='CLI Tox client'
license=('GPL3')
pkgver=0.7.0
pkgrel=4
depends=('curl'
         'desktop-file-utils'
         'freealut'
         'libnotify'
         'qrencode'
         'toxcore')
arch=('i686' 'x86_64')
url='https://github.com/JFreegman/toxic'
source=("https://github.com/JFreegman/$pkgname/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha256sums=('f11eab5dc3fd24ee329438f57dad068064c0900838f684af6596e64c68be7006')

build() {
  cd "$pkgname-$pkgver"
  # disable X11 because https://github.com/JFreegman/toxic/issues/277
  make PREFIX=/usr DISABLE_X11=1
}

package() {
  cd "$pkgname-$pkgver"
  make PREFIX=/usr DESTDIR="$pkgdir" install
}
