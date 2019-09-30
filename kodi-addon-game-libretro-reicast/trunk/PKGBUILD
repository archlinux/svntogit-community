# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-reicast
pkgver=0.1.0.11
_codename=Leia
pkgrel=7
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.reicast'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-reicast')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.reicast/archive/$pkgver-$_codename.tar.gz")
sha512sums=('22e58084e0747369c6b41b806b6ccc8b5ac7ee3d30af7289e802554d153dd393866c66bd25a6ef0fd90e6700d591476f38f6eaedbe44435fe09e3ba510b73add')

build() {
    cd "game.libretro.reicast-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.reicast-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

