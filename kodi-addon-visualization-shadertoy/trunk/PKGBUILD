# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-visualization-shadertoy
epoch=1
pkgver=1.2.3
_codename=Leia
pkgrel=8
pkgdesc="Shadertoy visualizer for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/visualization.shadertoy'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-visualization')
depends=('kodi' 'p8-platform' 'glm')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/visualization.shadertoy/archive/$pkgver-$_codename.tar.gz")
sha512sums=('ea6aafd9afe221b3f12584f081eb55db29dd3a4483b6eb9cb53f8ccff105c3fd9bea9ced3badb171c5b2795387afd062d10b1b2f1dca31b1efcd896c89131958')

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

