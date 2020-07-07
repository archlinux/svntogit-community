# Maintainer: Thore Bödecker <foxxx0@archlinux.org>
# Contributor: Hanspeter Porner <dev@open-music-kontrllers.ch>
pkgname=cunit
_pkgname=CUnit
pkgver=2.1.3
_pkgver='2.1-3'
pkgrel=3
epoch=
pkgdesc='A Unit Testing Framework for C'
arch=('x86_64')
url='http://cunit.sourceforge.net'
license=('LGPL2.1')
depends=('glibc')
makedepends=('glibc' 'libtool' 'automake')
source=("https://downloads.sourceforge.net/project/cunit/$_pkgname/$_pkgver/$_pkgname-$_pkgver.tar.bz2")
sha512sums=('547b417109332446dfab8fda17bf4ccd2da841dc93f824dc90a20635bcf1fb80fb2176500d8a0906940f3f3d3e2f77b2d70a71090c9ab84ad9af43f3582bc487')

prepare() {
  cd "${srcdir}/${_pkgname}-${_pkgver}"
}

build() {
  cd "${srcdir}/${_pkgname}-${_pkgver}"

  libtoolize --force --copy
  aclocal
  autoheader
  automake --add-missing --include-deps --copy
  autoconf

  ./configure \
    --prefix=/usr \
    --enable-automated \
    --enable-basic \
    --enable-console \
    --enable-test \
    --enable-shared \
    --enable-static
  make
}

check() {
  cd "${srcdir}/${_pkgname}-${_pkgver}"
  ./CUnit/Sources/Test/test_cunit
}

package() {
  cd "${srcdir}/${_pkgname}-${_pkgver}"

  make DESTDIR="${pkgdir}/" install

  rm -r "${pkgdir}/usr/share/CUnit"
  mv "${pkgdir}/usr/doc" "${pkgdir}/usr/share/"
}
