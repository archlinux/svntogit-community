# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-visualization-waveform
epoch=1
pkgver=2.0.1
_codename=Leia
pkgrel=12
pkgdesc="Waveform visualizer for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/visualization.waveform'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-visualization')
depends=('kodi' 'glu')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/visualization.waveform/archive/$pkgver-$_codename.tar.gz")
sha512sums=('3ba3a3b92d7bbe5e82374daf92fe1054ee80fc316e8b63d0543248406ab7c341831f085f50221aa0bf9ea534c2eb37221c8c165aa553b8c8dbe5cae1b58c3229')

build() {
    cd "visualization.waveform-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "visualization.waveform-$pkgver-$_codename"
    make DESTDIR="$pkgdir/" install
}

