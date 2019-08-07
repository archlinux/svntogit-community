# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-game-libretro-melonds
pkgver=0.8.2.3
_codename=Leia
pkgrel=1
pkgdesc="Libretro wrapper for Kodi's Game API"
arch=('x86_64')
url='https://github.com/kodi-game/game.libretro.melonds'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-game')
depends=('kodi-addon-game-libretro' 'libretro-melonds')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kodi-game/game.libretro.melonds/archive/$pkgver-$_codename.tar.gz")
sha512sums=('8cb5902de05f1631833aff14f535deb97c2209d73ac54074ab5e13f212fc979e2644d0a2e816c960448907418d8335b5dd351cdf7ef536e678193b19e73082b9')

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

