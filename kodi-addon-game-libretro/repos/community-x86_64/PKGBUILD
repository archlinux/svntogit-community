# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro
pkgver=1.1.0
_codename=Leia
pkgrel=9
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi' 'kodi-platform' 'libretro-core-info')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro/archive/$pkgver-$_codename.tar.gz")
sha512sums=('80cc868d57d4284085a7cd736930da6f1b2440cbd8667a20634c329c282e7f0b79158d4d510504a230427fae4d84d9ae29c7a76fab5e2a23820bfa72d75a8e91')

build() {
    cd "game.libretro-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

