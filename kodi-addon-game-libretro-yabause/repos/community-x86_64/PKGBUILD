# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-yabause
pkgver=0.9.14.1
_codename=Leia
pkgrel=5
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.yabause'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-yabause')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.yabause/archive/$pkgver-$_codename.tar.gz")
sha512sums=('88cf84fc6f60f323b40ab787a0e3ff7b0257b810d721d359c5148e8f0d4e08403302b06c6e4ed9421ab4a95943546f33d82ca1fd5f45b9a9c42178de6d62a72c')

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

