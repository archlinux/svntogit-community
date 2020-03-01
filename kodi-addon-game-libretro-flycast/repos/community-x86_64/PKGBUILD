# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-flycast
pkgver=0.1.0.17
_codename=Leia
pkgrel=1
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.reicast'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-flycast')
makedepends=('cmake' 'kodi-dev')
replaces=('kodi-addon-game-libretro-reicast')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.reicast/archive/$pkgver-$_codename.tar.gz")
sha512sums=('955a6368eb66ee8d9247424620adea22e5bf3d0ca18bf66ce7b82f323a0f49ec9ab8e1ce41a829646ca10cc719ae0f840345e61de60a5a6513224c83acce630c')

build() {
    cd "game.libretro.flycast-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.flycast-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

