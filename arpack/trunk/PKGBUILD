# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: William Rea <sillywilly@gmail.com>
# Contributor: Stefan Husmann <stefan-husmann@t-online.de>

pkgname=arpack
pkgver=3.9.0
pkgrel=1
arch=(x86_64)
pkgdesc='Fortran77 subroutines for solving large scale eigenvalue problems'
url='https://github.com/opencollab/arpack-ng'
license=(BSD)
depends=(lapack openmpi)
makedepends=(gcc-fortran git)
provides=(arpack-ng)
source=("git+$url#commit=6c7a3240d8af41ec5190fe241d4cd27e1022c754") # tag: 3.9.0
b2sums=('SKIP')

prepare() {
  cd $pkgname-ng
  ./bootstrap
}

build() {
  cd $pkgname-ng
  ./configure --enable-icb --enable-mpi --prefix=/usr
  make F77=mpif77 \
    CFLAGS+=" $(pkg-config --cflags ompi-f77) " \
    LIBS+=" $(pkg-config --libs ompi-f77) "
}

package() {
  cd $pkgname-ng
  make DESTDIR="$pkgdir" install
  install -Dm644 COPYING "$pkgdir/usr/share/licenses/$pkgname/COPYING"
}
