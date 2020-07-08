# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro
pkgver=1.1.1
_codename=Leia
pkgrel=6
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi' 'kodi-platform' 'libretro-core-info')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro/archive/$pkgver-$_codename.tar.gz")
sha512sums=('f26776eba765a010a86994a02658045ca0c1e887481a31d90ae388765620fb1a0cbd4da79285ae161e99feb311ca9ddccd25193a73a22e7c5f19a78ff1164920')

build() {
    cd "game.libretro-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

