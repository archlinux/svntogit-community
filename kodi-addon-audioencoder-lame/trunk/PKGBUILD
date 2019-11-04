# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-audioencoder-lame
epoch=1
pkgver=2.0.3
_codename=Leia
pkgrel=1
pkgdesc="LAME Audio Encoder add-on for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/audioencoder.lame'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-audioencoder')
provides=('kodi-audioencoder-lame')
replaces=('kodi-audioencoder-lame')
depends=('kodi' 'lame')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/audioencoder.lame/archive/$pkgver-$_codename.tar.gz")
sha512sums=('3f81360b70cf66c964f560a64fcb4dcc9fabcfae0d03db2195e1162b11721e7511191d6207ec49b171eaee4b4d3af8026204cf00facbf312e4f4583ab504d90f')

build() {
    cd "audioencoder.lame-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "audioencoder.lame-$pkgver-$_codename"
    make DESTDIR="$pkgdir/" install
}

