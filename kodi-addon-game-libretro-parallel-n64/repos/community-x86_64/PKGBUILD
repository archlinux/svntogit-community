# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-parallel-n64
pkgver=2.0.0.3
_codename=Leia
pkgrel=3
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.parallel_n64'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-parallel-n64')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.parallel_n64/archive/$pkgver-$_codename.tar.gz")
sha512sums=('68fec534213a770ec4f942a53608bbefce1244e6c26287526fc6fe4880520c9402a03f4ee27dbb6bcd1daaeaab6f466d895377d4d2e6684be4d65888268a745a')

build() {
    cd "game.libretro.parallel_n64-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.parallel_n64-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

