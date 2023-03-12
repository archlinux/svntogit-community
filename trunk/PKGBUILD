# Maintainer: Alexander <xyproto@archlinux.org>

pkgname=gtk2-compat
pkgver=1.0.0
pkgrel=4
pkgdesc='Simulates the presence of GTK+2, but tries to use GTK+3'
arch=(any)
url='https://github.com/openSUSE/gtk2-compat'
license=(GPL2)
depends=(gtk3)
conflicts=(gtk2)
makedepends=(git)
source=("git+$url#commit=24913dc1b4ec13b870e87399fda1ae050f1d4eee") # no tags available, this is master from 2015-03-11
b2sums=(SKIP)

prepare() {
  cd $pkgname
  autoreconf -fiv
}

build() {
  cd $pkgname
  ./configure --prefix=/usr
  make
}

package() {
  DESTDIR="$pkgdir" make -C $pkgname install
}
