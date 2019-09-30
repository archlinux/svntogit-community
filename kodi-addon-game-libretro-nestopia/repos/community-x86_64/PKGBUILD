# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-nestopia
pkgver=1.50.0.6
_codename=Leia
pkgrel=3
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.nestopia'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-nestopia')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.nestopia/archive/$pkgver-$_codename.tar.gz")
sha512sums=('264fe60a586f27c29175172218f6cd205d7558b4848e95a19808f326ce52f32a2d5f60e6b22ef27417739ec40ba766e7cc9e6fd360bdd167d946f3e2ce19333c')

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

