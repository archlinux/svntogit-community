# Maintainer: Jiachen Yang <farseerfc@gmail.com>
# AUR Maintainer: Vlad M. <vlad@archlinux.net>

pkgname=toxic
pkgdesc='CLI Tox client'
license=('GPL3')
pkgver=0.7.1
pkgrel=1
depends=('curl'
         'desktop-file-utils'
         'freealut'
         'libnotify'
         'qrencode'
         'toxcore')
arch=('i686' 'x86_64')
url='https://github.com/JFreegman/toxic'
source=("https://github.com/JFreegman/$pkgname/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('c304b07a67ed27a25394590eb8759b5dd957605be4eb9e64590d4580da0977e1cd201e8b95ae1b31e995772560510ceb0643028696e2df69e1f5d0dff575b553')

build() {
  cd "$pkgname-$pkgver"
  # disable X11 because https://github.com/JFreegman/toxic/issues/277
  make PREFIX=/usr DISABLE_X11=1
}

package() {
  cd "$pkgname-$pkgver"
  make PREFIX=/usr DESTDIR="$pkgdir" install
}
