# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-desmume
pkgver=0.0.1.2
_codename=Leia
pkgrel=3
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.desmume'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-desmume')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.desmume/archive/$pkgver-$_codename.tar.gz")
sha512sums=('4afba20fc9602f900805f47b5c0aaee3539122ddeda12ba51ccc6b1742a52663a175d592187084c8474e43e67dd384f866a6b9b561f195e93f5be8824b3592e7')

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

