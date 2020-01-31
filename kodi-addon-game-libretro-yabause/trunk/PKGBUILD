# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-yabause
pkgver=0.9.15.6
_codename=Leia
pkgrel=1
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.yabause'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-yabause')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.yabause/archive/$pkgver-$_codename.tar.gz")
sha512sums=('26324176f5591585ad63e7affe1b76102ee408e171e2d23973006d9da987cdeac1abfe18c5caecd2e9ffaa31a509ae077da384623a33c2edf0c5dcadb56402ab')

build() {
    cd "game.libretro.yabause-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.yabause-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

