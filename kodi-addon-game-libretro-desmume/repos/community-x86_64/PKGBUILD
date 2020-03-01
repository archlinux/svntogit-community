# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-desmume
pkgver=0.0.1.4
_codename=Leia
pkgrel=2
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.desmume'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-desmume')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.desmume/archive/$pkgver-$_codename.tar.gz")
sha512sums=('049e06e18a6a62e2d3ba07a8d5293cef6affb4864c9f70af74aca754cd562267d10b15bcb0b009ca2800a74557564147702a7a76c74852cdc58db85afb92f5f5')

build() {
    cd "game.libretro.desmume-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.desmume-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

