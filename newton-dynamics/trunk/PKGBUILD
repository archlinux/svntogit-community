# $Id$
# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Josh Taylor (deficite) <joshtaylor.mail@gmail.com> 
# Contributor: Christophe Robin (bombstrike) <crobin@php.net> 
pkgname=newton-dynamics
pkgver=2.36
pkgrel=1
pkgdesc="A simple physics API"
arch=('i686' 'x86_64')
url="http://www.newtondynamics.com"
license=('custom')
depends=()
makedepends=('unrar')
source=("http://newton-dynamics.googlecode.com/files/newton-dynamics-${pkgver}.rar")
noextract=("newton-dynamics-${pkgver}.rar")
md5sums=('0dffa112d0a6ea39ad9e904e555da69a')

_srcdir="${srcdir}/newton-dynamics-${pkgver}"
[[ "$CARCH" = "i686" ]]  && platform="linux32"
[[ "$CARCH" = "x86_64" ]] && platform="linux64"
builddir="${_srcdir}/coreLibrary_200/projets/${platform}"

build() {

  # clean build directory
  [[ -d "${_srcdir}" ]] && rm -Rf "${_srcdir}"

  # decompress package
  cd "${srcdir}"
  unrar x "newton-dynamics-${pkgver}.rar"

  # needed for building
  mkdir -p "${_srcdir}/packages/${platform}"
  
  ## build lib
  cd "${builddir}"
  sed -i 's/ -o libNewton.so/ -lpthread -lstdc++ -o libNewton.so/' makefile
  sed -i 's/Debug\.cpp.*$/Debug \\/g' makefile
  make
}

package() {
  install -D -m644 "${builddir}/libNewton.a" "${pkgdir}/usr/lib/libNewton.a"
  install -D -m755 "${builddir}/libNewton.so" "${pkgdir}/usr/lib/libNewton.so"
  install -D -m644 "${_srcdir}/coreLibrary_200/source/newton/Newton.h" "${pkgdir}/usr/include/Newton.h"
}
