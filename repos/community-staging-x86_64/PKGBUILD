# Maintainer: Jaroslav Lichtblau <svetlemodry@archlinux.org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: David Dent <thewinch@gmail.com>
# Contributor: orbisvicis <orbisvicis@gmail.com>

pkgname=mapnik
pkgver=3.0.22
pkgrel=3
pkgdesc="Free Toolkit for developing mapping applications and rendering beautiful maps"
arch=('x86_64')
url="https://mapnik.org/"
license=('LGPL')
depends=('boost1.69-libs' 'cairo' 'freetype2' 'gdal' 'harfbuzz' 'icu' 'libjpeg-turbo' 'libpng'
         'libtiff' 'libwebp' 'libxml2' 'postgresql-libs' 'proj' 'sqlite' 'zlib')
makedepends=('boost1.69' 'scons')
source=(https://github.com/$pkgname/$pkgname/releases/download/v$pkgver/$pkgname-v$pkgver.tar.bz2
        mapnik-freetype2.patch::https://github.com/mapnik/mapnik/pull/3892.patch)
sha256sums=('930612ad9e604b6a29b9cea1bc1de85cf7cf2b2b8211f57ec8b6b94463128ab9'
            '774a8590b698e9dc2a483e6ff48781ed0400ba06b901f12a1ed50c9114833d47')

prepare() {
  cd "${srcdir}"/$pkgname-v$pkgver

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
