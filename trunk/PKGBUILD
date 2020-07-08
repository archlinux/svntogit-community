# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-audioencoder-flac
epoch=1
pkgver=2.0.6
_codename=Leia
pkgrel=7
pkgdesc="FLAC Audio Encoder add-on for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/audioencoder.flac'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-audioencoder')
provides=('kodi-audioencoder-flac')
replaces=('kodi-audioencoder-flac')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/audioencoder.flac/archive/$pkgver-$_codename.tar.gz")
sha512sums=('7de2b0f5b36b62bc1f066e5c99fba2aa61baac5f204a75556172aa95332999806a34babef08ac5e516e62a123b83d3befaee6654d3089ebd1a305335a40d88b5')

build() {
    cd "audioencoder.flac-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
	cd "audioencoder.flac-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

