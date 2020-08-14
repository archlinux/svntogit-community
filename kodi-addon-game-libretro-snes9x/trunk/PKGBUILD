# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-snes9x
pkgver=1.60.0.12
_codename=Leia
pkgrel=1
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.snes9x'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-snes9x')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.snes9x/archive/$pkgver-$_codename.tar.gz")
sha512sums=('d307c0f8c9b0ba52f316513d3ac4660b87d48a4e7b55222d3019ffb487e01f3ec3f4164a633cda3d172c2b8bcdbcc23d5e41a258f4f2f98c59b2a7bc15562d4f')

build() {
    cd "game.libretro.snes9x-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.snes9x-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

