# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-parallel-n64
pkgver=2.0.0.7
_codename=Leia
pkgrel=1
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.parallel_n64'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-parallel-n64')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.parallel_n64/archive/$pkgver-$_codename.tar.gz")
sha512sums=('1159af299b3c564f19b9e53d0ce87680a7f8eb52cf994b617430c5dd6d93cb071efccd1eab1e20959c1a7b6041a7b362866a369a03bfc1deeec9de85c5a4d012')

build() {
    cd "game.libretro.parallel_n64-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.parallel_n64-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

