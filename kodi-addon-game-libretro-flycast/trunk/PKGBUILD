# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-flycast
pkgver=0.1.0.18
_codename=Leia
pkgrel=1
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.reicast'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-flycast')
makedepends=('cmake' 'kodi-dev')
replaces=('kodi-addon-game-libretro-reicast')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.reicast/archive/$pkgver-$_codename.tar.gz")
sha512sums=('f9dcffcf25fbb04e2e9ec8bebde1fea36fefc425e194cdf9ec1d6d54729516504377b38181621d7a8c3dcfdd89f8fb20c9f06fa0653dfac0f9c435fdfaa80522')

build() {
    cd "game.libretro.flycast-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.flycast-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

