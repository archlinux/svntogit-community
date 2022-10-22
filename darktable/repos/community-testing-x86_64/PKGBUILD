# Maintainer: Bruno Pagani <archange@archlinux.org>
# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Christian Himpel <chressie at gmail dot com>
# Contributor: Johannes Hanika <hanatos at gmail dot com>

pkgname=darktable
epoch=2
pkgver=4.0.1
pkgrel=2
pkgdesc="Utility to organize and develop raw images"
arch=(x86_64)
url="https://darktable.org"
license=(GPL3)
depends=(pugixml libjpeg-turbo colord-gtk libgphoto2 openexr lensfun iso-codes zlib
         exiv2 flickcurl openjpeg2 graphicsmagick lua osm-gps-map libsecret openmp
         gmic libavif jasper)
optdepends=('dcraw: base curve script'
            'perl-image-exiftool: base curve script'
            'imagemagick: base curve and noise profile scripts'
            'ghostscript: noise profile script'
            'portmidi: game and midi controller input devices'
            'gnuplot: noise profile script')
makedepends=(cmake intltool desktop-file-utils llvm clang portmidi python-jsonschema libwebp)
options=(debug)
source=("https://github.com/darktable-org/darktable/releases/download/release-${pkgver}/darktable-${pkgver}.tar.xz"{,.asc})
sha256sums=('5fef81e0c0079977a3cdc3627eed777280c2346d023c5d176c1f4a62cbe51d68'
            'SKIP')
validpgpkeys=(C4CBC150699956E2A3268EF5BB5CC8295B1779C9  # darktable releases <release@darktable.org>
              F10F9686652B0E949FCD94C318DCA123F949BD3B) # Pascal Obry <pascal@obry.net>

build() {
    cmake -B build -S ${pkgname}-${pkgver} \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_INSTALL_LIBDIR=/usr/lib \
        -DCMAKE_INSTALL_LIBEXECDIR=/usr/lib \
        -DCMAKE_BUILD_TYPE=Release \
        -DBINARY_PACKAGE_BUILD=1 \
        -DBUILD_USERMANUAL=False \
        -DUSE_LIBSECRET=ON \
        -DUSE_LUA=ON \
        -DUSE_COLORD=ON \
        -DBUILD_CURVE_TOOLS=ON \
        -DBUILD_NOISE_TOOLS=ON \
        -DRAWSPEED_ENABLE_LTO=ON \
        -DPROJECT_VERSION=${pkgver}
    make -C build
}

package() {
    make -C build DESTDIR="${pkgdir}" install
    ln -s darktable/libdarktable.so "${pkgdir}"/usr/lib/libdarktable.so
}
