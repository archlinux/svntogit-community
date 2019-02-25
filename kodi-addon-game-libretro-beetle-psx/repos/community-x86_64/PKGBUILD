# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-beetle-psx
pkgver=0.9.44.7
_codename=Leia
pkgrel=3
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.beetle-psx'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-beetle-psx')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.beetle-psx/archive/$pkgver-$_codename.tar.gz")
sha512sums=('4a4f669aa75959395185f862e171c6a49a6105e4fa850a6cf56148d2f130c61e0e66a71011679439e46ef38ac41114da8b803abc363740b1f94de72d7b85cdb0')

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

