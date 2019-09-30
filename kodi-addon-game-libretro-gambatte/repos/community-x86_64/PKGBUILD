# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-gambatte
pkgver=0.5.0.7
_codename=Leia
pkgrel=3
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.gambatte'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-gambatte')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.gambatte/archive/$pkgver-$_codename.tar.gz")
sha512sums=('d5b7417b36948bb4087ec53e6bd84681e014c5961ed92a9a094a7adfe18e5326f51a8935cbb26aef62907ea393436403ac9e181e113552bc13965583ca4abd92')

build() {
    cd "game.libretro.gambatte-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.gambatte-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

