# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-cpblobs
epoch=1
pkgver=1.1.0
pkgrel=1
pkgdesc="CpBlobs screensaver for Kodi"
arch=('x86_64')
url='github.com/notspiff/screensaver.cpblobs'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi' 'soil')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/notspiff/screensaver.cpblobs/archive/v$pkgver.tar.gz")
sha512sums=('265aa6a87e6e98ea808e665910ea0d13808f33e1ecf7645c437814f312019168e10a5728da5d3e1fa762cd770a2afbb70d20682c8975b0fc8ede232e6baf486d')

build() {
    cd "screensaver.cpblobs-$pkgver"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
    cd "screensaver.cpblobs-$pkgver"
	make DESTDIR="$pkgdir/" install
}

