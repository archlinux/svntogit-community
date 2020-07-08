# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-mupen64plus
pkgver=2.5.0.6
_codename=Leia
pkgrel=15
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.mupen64plus'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-mupen64plus-next')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.mupen64plus/archive/$pkgver-$_codename.tar.gz")
sha512sums=('f8f8902deac7657c060806303e2dd29515ad6d6af196236456e9ef78cc34c1c2020fccdac2b8b7dbf41d3ff4c374dae79211e61d5d9685e0cd661889118effe7')

build() {
    cd "game.libretro.mupen64plus-$pkgver-$_codename"
    sed -e 's/mupen64plus_libretro/mupen64plus_next_libretro/g' \
        -i CMakeLists.txt
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.mupen64plus-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

