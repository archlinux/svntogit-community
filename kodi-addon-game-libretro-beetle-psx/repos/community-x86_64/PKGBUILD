# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-beetle-psx
pkgver=0.9.44.12
_codename=Leia
pkgrel=9
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.beetle-psx'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-beetle-psx')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.beetle-psx/archive/$pkgver-$_codename.tar.gz")
sha512sums=('f65ede939c9530c41a6118e00ce1df1b625de3478a6d1823fbdf05b2003c70583cd5859a2b481a6656e88df0a47ee4e0c26b807a3bd38862e8969976aa3995e2')

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

