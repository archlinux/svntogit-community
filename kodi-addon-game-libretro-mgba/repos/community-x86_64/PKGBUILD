# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-mgba
pkgver=0.8.0.8
_codename=Leia
pkgrel=1
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.mgba'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-mgba')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.mgba/archive/$pkgver-$_codename.tar.gz")
sha512sums=('c84eaaf1716da2a904355f92a44f0ab788d03e292f1c906d50887315edad0cd81b44654a137e74e4c1b76635380f6436044b7af697fe1791630281a3d8dd1c10')

build() {
    cd "game.libretro.mgba-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.mgba-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

