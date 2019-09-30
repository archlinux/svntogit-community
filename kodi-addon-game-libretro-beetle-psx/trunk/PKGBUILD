# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-beetle-psx
pkgver=0.9.44.9
_codename=Leia
pkgrel=3
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.beetle-psx'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-beetle-psx')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.beetle-psx/archive/$pkgver-$_codename.tar.gz")
sha512sums=('7ace99ffd93f220ef0ca21a35266712da8ff977035c0960e93a34ce96c7332369045732f571e48f4825dbd4a22bc569dba2cdc2c3844fac20172b53dc54a27e0')

build() {
    cd "game.libretro.beetle-psx-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.beetle-psx-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

