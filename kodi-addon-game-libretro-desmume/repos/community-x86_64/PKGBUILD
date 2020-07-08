# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-desmume
pkgver=0.0.1.5
_codename=Leia
pkgrel=6
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.desmume'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-desmume')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.desmume/archive/$pkgver-$_codename.tar.gz")
sha512sums=('22891ce264b8118315cf5ac54d6ac378ec2c157341378a3ff34c07d283c57d45e71cf1baf1a7e0a29fe6d5fedbadf01e2d84cb51f0edd43924c95ecf967e23ce')

build() {
    cd "game.libretro.desmume-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.desmume-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

