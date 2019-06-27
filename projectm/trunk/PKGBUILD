# Maintainer: Giancarlo Razzolini <grazzolini@archlinux.org>
# Contributor: Alexander F Rødseth <xyproto@archlinux.org>
# Contributor: Lukas Fleischer <lfleischer@archlinux.org>
# Contributor: Alexander Baldeck <alexander@archlinux.org>
# Contributor: Denis A. Altoe Falqueto <denisfalqueto@gmail.com>

pkgbase=projectm
pkgname=('projectm' 'projectm-sdl' 'projectm-pulseaudio')
pkgver=3.1.0
pkgrel=5
arch=('x86_64')
url='https://github.com/projectM-visualizer/projectm'
license=('LGPL')
makedepends=('mesa-libgl' 'glm' 'qt5-base' 'ftgl' 'glew' 'sdl2' 'libpulse')
source=("https://github.com/projectM-visualizer/$pkgbase/releases/download/v$pkgver/projectM-$pkgver.tar.gz"
        '112.patch')
sha256sums=('36f67c362d5fa405d73f938c183d8c4a27d1ee6058a68b66c11ace2e89f97da8'
            '063c22113fb4518eba847b3d293b68e0c0ada45b6c9893bd7de17a3416fb0753')

prepare() {
    cd "projectM-$pkgver"
    patch -p1 -i "$srcdir/112.patch"
}

build() {
    cd "projectM-$pkgver"
    ./configure --prefix=/usr --enable-gles --enable-sdl --enable-threading --enable-qt
    make
}

package_projectm() {
    pkgdesc='Music visualizer which uses 3D accelerated iterative image based rendering'
    depends=('libgl' 'glm' 'ftgl' 'glew')


    cd "$srcdir/projectM-$pkgver"
    make DESTDIR="$pkgdir" install-data-am
    cd "$srcdir/projectM-$pkgver/src"
    make DESTDIR="$pkgdir" install-am
    cd "$srcdir/projectM-$pkgver/src/libprojectM"
    make DESTDIR="$pkgdir" install
    cd "$srcdir/projectM-$pkgver/src/NativePresets"
    make DESTDIR="$pkgdir" install

    find "$pkgdir" -iname "\.*" -delete
}

package_projectm-sdl() {
    pkgdesc='Music visualizer which uses 3D accelerated iterative image based rendering (sdl)'
    depends=('projectm' 'sdl2')

    cd "$srcdir/projectM-$pkgver/src/projectM-sdl"
    make DESTDIR="$pkgdir" install
}

package_projectm-pulseaudio() {
    pkgdesc='Music visualizer which uses 3D accelerated iterative image based rendering (pulseaudio)'
    depends=('projectm' 'qt5-base' 'libpulse')

    cd "$srcdir/projectM-$pkgver/src/projectM-pulseaudio"
    make DESTDIR="$pkgdir" install
}
