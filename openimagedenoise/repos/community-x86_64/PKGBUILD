# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>
# Maintainer: Sven-Hendrik Haase <svenstaro@archlinux.org>

pkgname=openimagedenoise
pkgver=1.4.3
pkgrel=1
pkgdesc='Intel(R) Open Image Denoise library'
arch=('x86_64')
url='https://openimagedenoise.github.io'
license=('Apache')
depends=('intel-tbb')
makedepends=('cmake' 'ninja' 'ispc' 'python')
source=("https://github.com/OpenImageDenoise/oidn/releases/download/v${pkgver}/oidn-${pkgver}.src.tar.gz")
sha512sums=('6fbdf347763c0734140195a523cf0878b1dbd91d4943c9ce4928f6991549f8b3d5ab4d57b90e20a8d04a87d00e3a1554ce73a3a3c1e64fcb016a3c1f8aa07982')

build() {
    cd oidn-$pkgver

    cmake \
        -B build \
        -G Ninja \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release
    ninja -C build
}

package() {
    cd oidn-$pkgver
    DESTDIR="$pkgdir" ninja -C build install
}
