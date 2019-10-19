# Maintainer: Bruno Pagani <archange@archlinux.org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Christian Himpel <chressie at gmail dot com>
# Contributor: Johannes Hanika <hanatos at gmail dot com>

pkgname=darktable
epoch=2
pkgver=2.6.2
pkgrel=3
pkgdesc="Utility to organize and develop raw images"
arch=('x86_64')
url="https://darktable.org"
license=('GPL3')
depends=('pugixml' 'libjpeg-turbo' 'colord-gtk' 'libgphoto2' 'openexr' 'lensfun' 'iso-codes'
         'exiv2' 'flickcurl' 'openjpeg2' 'graphicsmagick' 'lua' 'osm-gps-map' 'libsecret')
makedepends=('cmake' 'intltool' 'desktop-file-utils' 'llvm' 'clang' 'python-jsonschema' 'libwebp')
source=("https://github.com/darktable-org/darktable/releases/download/release-${pkgver}/darktable-${pkgver/rc/.rc}.tar.xz"{,.asc}
         darktable-gcc9.patch)
sha256sums=('9cb9efbb09a40375ff05cef89343235a621c58339539e44985470a029a7ffb45'
            'SKIP'
            '8ab880dd35ffd30e8eecd0468f4173f50231655cea2a22ac1f0f9d56f89ce7ee')
validpgpkeys=('C4CBC150699956E2A3268EF5BB5CC8295B1779C9'  # darktable releases <release@darktable.org>
              'F10F9686652B0E949FCD94C318DCA123F949BD3B') # Pascal Obry <pascal@obry.net>

prepare() {
    mkdir -p build

    cd $pkgname-$pkgver
    patch -p1 -i ../darktable-gcc9.patch # Fix build with GCC 9 (Gentoo)
}

build() {
    cd build
    cmake ../${pkgname}-${pkgver/rc/~rc} \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_INSTALL_LIBDIR=/usr/lib \
        -DCMAKE_BUILD_TYPE=Release \
        -DBINARY_PACKAGE_BUILD=1 \
        -DBUILD_USERMANUAL=False \
        -DUSE_LIBSECRET=ON \
        -DUSE_LUA=ON \
        -DUSE_COLORD=ON \
        -DRAWSPEED_ENABLE_LTO=ON \
        -DPROJECT_VERSION=${pkgver}
    make
}

package() {
    cd build
    make DESTDIR="${pkgdir}" install
    ln -s darktable/libdarktable.so "${pkgdir}"/usr/lib/libdarktable.so
}
