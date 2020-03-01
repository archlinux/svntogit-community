# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-melonds
pkgver=0.8.3.6
_codename=Leia
pkgrel=2
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.melonds'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-melonds')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.melonds/archive/$pkgver-$_codename.tar.gz")
sha512sums=('30a03e7f0580bc0164ae07a5d29d4b2ad7f22855e317f273fb45bb3d4cc0363df5006de16f4813dda0a6d84e596ea938f8a4c8cf694087ee8165d96a8b4059b9')

build() {
    cd "game.libretro.melonds-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.melonds-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

