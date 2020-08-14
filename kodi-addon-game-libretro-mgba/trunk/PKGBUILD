# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-mgba
pkgver=0.8.3.11
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
sha512sums=('354a7f618bc9511d61bb72730fec36e5bd4f3a52f520bf51f80dd3f13526236c4e9e5b511600d870631c612da99bba5f31067f840baa0f8b6d1cf6efbbddeb31')

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

