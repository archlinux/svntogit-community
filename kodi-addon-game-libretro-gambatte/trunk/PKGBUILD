# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-gambatte
pkgver=0.5.0.5
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
sha512sums=('12ae2c7cb3659f072f5b525e4e58554cce2fd77ab80e78661e64cab7fcbac07c3060f35808440e72c09745d875c857b7fad9ea231608ff1bbad84ae5b49d8b13')

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

