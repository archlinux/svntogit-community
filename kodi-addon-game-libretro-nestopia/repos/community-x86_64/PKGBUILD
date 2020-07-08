# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-nestopia
pkgver=1.50.0.9
_codename=Leia
pkgrel=6
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.nestopia'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-nestopia')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.nestopia/archive/$pkgver-$_codename.tar.gz")
sha512sums=('1bac70812ecf58f74adcebbe9bb0520eee5eb070b307b79d9c0b7c2d5393b7191eea89b8a8b490c4626701993164b142864c999abb34f525d7e73a673c60b5a4')

build() {
    cd "game.libretro.nestopia-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.nestopia-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

