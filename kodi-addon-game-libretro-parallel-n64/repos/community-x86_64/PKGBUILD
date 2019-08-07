# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-parallel-n64
pkgver=2.0.0.2
_codename=Leia
pkgrel=1
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.parallel_n64'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-parallel-n64')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.parallel_n64/archive/$pkgver-$_codename.tar.gz")
sha512sums=('232ad26f5aa6b3a6b447c0e6845e4647b906f33963d9d9b6cb3eaa0db924ffd54a0f0fc85311668a04d5edfedb3ce9c9d69f056fabefeeafd0c1fe1ae3bae85e')

build() {
    cd "game.libretro.parallel_n64-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.parallel_n64-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

