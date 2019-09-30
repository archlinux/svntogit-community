# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-visualization-shadertoy
epoch=1
pkgver=1.1.10
_codename=Leia
pkgrel=6
pkgdesc="Shadertoy visualizer for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/visualization.shadertoy'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-visualization')
depends=('kodi' 'p8-platform')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/visualization.shadertoy/archive/$pkgver-$_codename.tar.gz")
sha512sums=('2d81edc2bffd29d2d33a8c67fdf84e65a53a2f204cc051df23d7904a763d6096b7c9839dfda9830e081ee465fcfacd656dc2959ace84ea4350e9d03cccc72712')

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

