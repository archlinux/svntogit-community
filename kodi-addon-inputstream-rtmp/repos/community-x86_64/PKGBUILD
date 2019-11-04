# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: kevku <kevku@gmx.com>

pkgname=kodi-addon-inputstream-rtmp
pkgver=2.0.6
_codename=Leia
pkgrel=1
pkgdesc="RTMP input stream add-on for Kodi"
arch=('x86_64')
url="https://github.com/xbmc/inputstream.rtmp"
license=('GPL2')
groups=('kodi-addons' 'kodi-addons-inputstream')
depends=('kodi' 'rtmpdump' 'p8-platform')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/inputstream.rtmp/archive/$pkgver-$_codename.tar.gz")
sha512sums=('38bc0813427d6ae201b305a208b91eee5087ee8226c8f26e7df4e82d5dc87ac3c0a0809abee3ff99fa995659bb8eba1d1ba2aeb7ee1059ef85aa45d9a0abfd3b')

build() {
    cd "inputstream.rtmp-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "inputstream.rtmp-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}
