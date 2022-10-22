# Maintainer: Jaroslav Lichtblau <svetlemodry@archlinux.org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: David Dent <thewinch@gmail.com>
# Contributor: orbisvicis <orbisvicis@gmail.com>

pkgname=mapnik
pkgver=3.1.0
pkgrel=14
pkgdesc="Free Toolkit for developing mapping applications and rendering beautiful maps"
arch=('x86_64')
url="https://mapnik.org/"
license=('LGPL')
depends=('boost-libs' 'cairo' 'freetype2' 'gdal' 'harfbuzz' 'icu' 'libjpeg-turbo' 'libpng'
         'libtiff' 'libwebp' 'libxml2' 'postgresql-libs' 'proj' 'sqlite' 'zlib')
makedepends=('boost' 'scons')
source=(https://github.com/$pkgname/$pkgname/releases/download/v$pkgver/$pkgname-v$pkgver.tar.bz2
        boost-1.80.patch
        scons4.patch)
sha256sums=('43d76182d2a975212b4ad11524c74e577576c11039fdab5286b828397d8e6261'
            'b80085fba71ea6ecd86ff98ebdf652490bf56507cb798076192ab3ce136f5eeb'
            '79a85ddba3ec17b86cb216e21442611498a9f2612f03e98708057b3c3a6e8b06')

prepare() {
  cd "${srcdir}"/$pkgname-v$pkgver
  patch -Np1 -i ../boost-1.80.patch

  # Partial fix to build with SCons 4 (https://bugs.archlinux.org/task/71630)
  patch -Np1 -i ../scons4.patch
}

build() {
  cd "${srcdir}"/$pkgname-v$pkgver
  scons configure  FAST=True \
    PREFIX="/usr" \
    INPUT_PLUGINS=all \
    XMLPARSER=libxml2 \
    DESTDIR="$pkgdir" \
    CUSTOM_CXXFLAGS="$CXXFLAGS -ffat-lto-objects" \
    CUSTOM_LDFLAGS="$LDFLAGS" \
    CUSTOM_DEFINES="-DACCEPT_USE_OF_DEPRECATED_PROJ_API_H=1"
  scons $(expr "$MAKEFLAGS" : '.*\(\-j[0-9]\+\)')
}

package(){
  cd "${srcdir}"/$pkgname-v$pkgver
  scons install
}
