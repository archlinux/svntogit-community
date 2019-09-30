# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-melonds
pkgver=0.8.2.5
_codename=Leia
pkgrel=3
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.melonds'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-melonds')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.melonds/archive/$pkgver-$_codename.tar.gz")
sha512sums=('9133de3a7aae4361d986999e700a17c6aa1bd6dd049e22b285d9479753d431e19ba2a5af46acb0ef077821fae7c042e9f798f4df36ff3cf5bc73429e6ca92018')

build() {
    cd "game.libretro.melonds-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "game.libretro.melonds-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

