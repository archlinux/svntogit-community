# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-desmume
pkgver=0.0.1.3
_codename=Leia
pkgrel=3
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.desmume'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-desmume')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.desmume/archive/$pkgver-$_codename.tar.gz")
sha512sums=('d62d51982699a664e67728edcf035c6ed6c57d2d8f4c06bb3c421f0fa5f58fd89e053c34b0b9d8cf794584d1989ad3e9cd9eca46e22d62658f20d192e1050651')

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

