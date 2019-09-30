# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-scummvm
pkgver=2.0.0.6
_codename=Leia
pkgrel=3
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.scummvm'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-scummvm')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.scummvm/archive/$pkgver-$_codename.tar.gz")
sha512sums=('042221de52e242da5544c72c4fc80ed01c61a502e5d382200612269aad9830fe6e441b2e46e30a32faf8cb43ca5ec3add985df11de81c8f32603cc291b3931e2')

build() {
    cd "game.libretro.scummvm-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.scummvm-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

