# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-snes9x
pkgver=1.60.0.11
_codename=Leia
pkgrel=1
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.snes9x'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-snes9x')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.snes9x/archive/$pkgver-$_codename.tar.gz")
sha512sums=('0d434053808f85b45ed7eb54de1dad8cb1d78b9e7c4cff25039620f622c942d10eb38c982c7ea92a160ec42f485a129a1b77692d6794628bf5ba0f778ea429a9')

build() {
    cd "game.libretro.snes9x-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.snes9x-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

