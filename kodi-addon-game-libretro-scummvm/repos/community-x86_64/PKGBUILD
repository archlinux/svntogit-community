# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-scummvm
pkgver=2.1.1.8
_codename=Leia
pkgrel=1
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.scummvm'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-scummvm')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.scummvm/archive/$pkgver-$_codename.tar.gz")
sha512sums=('9eb62ff210f7ff73cedc52c188e724ba1cc4728631fd93f5df2b9469d583831120022c89aa3bf92565b8a930006883789bd7db0fdf55ce56d9523f2786416aca')

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

