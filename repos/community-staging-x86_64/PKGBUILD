# Maintainer: Jaroslav Lichtblau <svetlemodry@archlinux.org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: David Dent <thewinch@gmail.com>
# Contributor: orbisvicis <orbisvicis@gmail.com>

pkgname=mapnik
pkgver=3.0.23
pkgrel=5
pkgdesc="Free Toolkit for developing mapping applications and rendering beautiful maps"
arch=('x86_64')
url="https://mapnik.org/"
license=('LGPL')
depends=('boost-libs' 'cairo' 'freetype2' 'gdal' 'harfbuzz' 'icu' 'libjpeg-turbo' 'libpng'
         'libtiff' 'libwebp' 'libxml2' 'postgresql-libs' 'proj' 'sqlite' 'zlib')
makedepends=('boost' 'scons')
source=(https://github.com/$pkgname/$pkgname/releases/download/v$pkgver/$pkgname-v$pkgver.tar.bz2
        mapnik-boost173.patch
        mapnik-std-c++14.patch
        mapnik-freetype2.patch::https://github.com/mapnik/mapnik/pull/3892.patch)
sha256sums=('4b1352e01f7ce25ab099e586d7ae98e0b74145a3bf94dd365cb0a2bdab3b9dc2'
            'fc6fb17c90dd1b2d861a5d8886797a5536bc31ab4b018ba1688f41fb25be27b4'
            '89b6f6be54feca2ba120516a39e20d3ae9706b7fbde140d73538f2727ab31fbe'
            '774a8590b698e9dc2a483e6ff48781ed0400ba06b901f12a1ed50c9114833d47')

prepare() {
  cd "${srcdir}"/$pkgname-v$pkgver

  patch -Np1 -i ../mapnik-boost173.patch

  # C++14 mode required by Boost.Geometry 1.75
  patch -Np1 -i ../mapnik-std-c++14.patch

  # Use pkg-config to find FreeType2 if available
  # https://github.com/mapnik/mapnik/pull/3892
  patch -Np1 -i "${srcdir}"/mapnik-freetype2.patch
}

build() {
  cd "${srcdir}"/$pkgname-v$pkgver
  scons configure  FAST=True \
    PREFIX="/usr" \
    INPUT_PLUGINS=all \
    XMLPARSER=libxml2 \
    DESTDIR="$pkgdir" \
    CUSTOM_CXXFLAGS="$CXXFLAGS" \
    CUSTOM_LDFLAGS="$LDFLAGS" \
    CUSTOM_DEFINES="-DACCEPT_USE_OF_DEPRECATED_PROJ_API_H=1"
  scons $(expr "$MAKEFLAGS" : '.*\(\-j[0-9]\+\)')
}

package(){
  cd "${srcdir}"/$pkgname-v$pkgver
  scons install
}
