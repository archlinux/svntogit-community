# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-beetle-psx
pkgver=0.9.44.10
_codename=Leia
pkgrel=1
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.beetle-psx'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-beetle-psx')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.beetle-psx/archive/$pkgver-$_codename.tar.gz")
sha512sums=('54988342443a3789d7d179600bafa99b347d2e5ece75cf47f7d1935d162aa74c2aecc6a93501f84fedfcb0bc2c21b621bf403a4ce4b45b02a77858a237ff82a4')

build() {
    cd "game.libretro.beetle-psx-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.beetle-psx-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

