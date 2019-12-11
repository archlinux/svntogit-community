# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-gambatte
pkgver=0.5.0.8
_codename=Leia
pkgrel=1
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.gambatte'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-gambatte')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.gambatte/archive/$pkgver-$_codename.tar.gz")
sha512sums=('fcb2c0bd61fd37f1a9c757903a1eb46f465dee3a0b6dd5711a6f7ad5e391a96c3b34c07c83a6bfaa3ac535a07c32368122ba5d886ad322658b601f6231cd9b2c')

build() {
    cd "game.libretro.gambatte-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.gambatte-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

