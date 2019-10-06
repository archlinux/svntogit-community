# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-yabause
pkgver=0.9.15.4
_codename=Leia
pkgrel=4
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.yabause'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-yabause')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.yabause/archive/$pkgver-$_codename.tar.gz")
sha512sums=('691abea72a89e333c3d02f5f0fca7a106b58df830bc44c3872e0d4a1b7dad405db34d27530ea3a9757b7b3c97c754f2f7a1015f05fa1254e04f72f6dd48056ac')

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

