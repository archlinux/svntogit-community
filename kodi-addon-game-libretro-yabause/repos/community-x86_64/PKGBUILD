# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-yabause
pkgver=0.9.15.7
_codename=Leia
pkgrel=1
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.yabause'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-yabause')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.yabause/archive/$pkgver-$_codename.tar.gz")
sha512sums=('9be56b6ac86f26a55f9aa176d92fd1503cfeb1c3479f0e9eb24f1470f2e6b9cb7dd15839ceb31d3aec3f11c3f8f22ab3a1eeda1e6a64b657a7e8b5f0199a3de2')

build() {
    cd "game.libretro.yabause-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.yabause-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

