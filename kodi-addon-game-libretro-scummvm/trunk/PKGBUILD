# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-scummvm
pkgver=2.1.0.7
_codename=Leia
pkgrel=1
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.scummvm'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-scummvm')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.scummvm/archive/$pkgver-$_codename.tar.gz")
sha512sums=('fe23ef1e7a7cb87d5134bd22278b68ec53061c6c2b4bda6c6d0f21d7cab013131cab38c03be9d519b4a8edb2c9a7e5be3b18d249c7ac2bfb1d6829637917bd0f')

build() {
    cd "game.libretro.scummvm-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.scummvm-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

