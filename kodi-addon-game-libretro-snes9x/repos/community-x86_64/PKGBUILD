# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-snes9x
pkgver=1.60.0.10
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
sha512sums=('0b59b4d3038a0e85d2380a7de1ec7c8f70bc37679c7fe6ad1fc284ba2dabb195274c732dc7e9e6a78d4337c935de84087297424ec8afc981f08a70fba1150f31')

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

