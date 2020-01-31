# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: kevku <kevku@gmx.com>

pkgname=kodi-addon-inputstream-rtmp
pkgver=2.0.8
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
sha512sums=('fca7de7cf5ad65081bd25ea1a6cb5c1cdf41f72ba4460256918178060b62e04d389c293add1a10faf899750745ba77244cfb7af97ba613b2abcf6862839c751b')

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
