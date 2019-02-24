# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-visualization-shadertoy
epoch=1
pkgver=1.1.9
_codename=Leia
pkgrel=4
pkgdesc="Shadertoy visualizer for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/visualization.shadertoy'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-visualization')
depends=('kodi' 'p8-platform')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/visualization.shadertoy/archive/$pkgver-$_codename.tar.gz")
sha512sums=('f829505525f46cb54ac205a52561dbf99f776350c0c34487438663d1c42dcd734f8c2e543c23550b4be61bab00d7f09beb63824935cd68de14328aaca44a5b95')

build() {
    cd "visualization.shadertoy-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "visualization.shadertoy-$pkgver-$_codename"
    make DESTDIR="$pkgdir/" install
}

