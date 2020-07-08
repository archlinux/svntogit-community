# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-melonds
pkgver=0.8.3.7
_codename=Leia
pkgrel=6
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.melonds'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-melonds')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.melonds/archive/$pkgver-$_codename.tar.gz")
sha512sums=('a3455d7931c0d0ab1078ac005ba99fa62c341c7953cfb1a900685900086d62378f075dea43b1be11b9b4ca9b11cd9eb4b826f9a9fa40107890eb8332500d1866')

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

