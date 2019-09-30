# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: kevku <kevku@gmx.com>

pkgname=kodi-addon-inputstream-rtmp
pkgver=2.0.5
_codename=Leia
pkgrel=2
pkgdesc="RTMP input stream add-on for Kodi"
arch=('x86_64')
url="https://github.com/xbmc/inputstream.rtmp"
license=('GPL2')
groups=('kodi-addons' 'kodi-addons-inputstream')
depends=('kodi' 'rtmpdump' 'p8-platform')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/inputstream.rtmp/archive/$pkgver-$_codename.tar.gz")
sha512sums=('178ecfedae24b2ca0b13de997861e89063eff929a6a1a2b0b6b3e32a45bddd238304466a9f1f52b6213db3faee93144ae77fc9c4045c3783780a50bc1ae11166')

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
