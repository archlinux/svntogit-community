# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-yabause
pkgver=0.9.15.8
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
sha512sums=('1eaa5b4989ad2c1c9ea84747e5854e7057cd8b57103ceaa574f2cd3f0ab8a472af2a6111d57ad75afa66336cae61d0abb4dcf804841d5dcba02e45b8ecfce0e0')

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

