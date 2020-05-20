# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Cedric Girard <cgirard.archlinux@valinor.fr>
# Contributor: kevku <kevku@gmx.com>

pkgname=kodi-addon-inputstream-adaptive
pkgver=2.4.5
_codename=Leia
pkgrel=1
pkgdesc="InputStream client for adaptive streams for Kodi 18+"
arch=('x86_64')
url="https://github.com/peak3d/inputstream.adaptive"
license=('GPL2')
groups=('kodi-addons' 'kodi-addons-inputstream')
depends=('kodi' 'kodi-platform')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/peak3d/inputstream.adaptive/archive/$pkgver-$_codename.tar.gz")
sha512sums=('b38e175fb21dcc155aa5b5cda4ffdbd26336a763c9ecf8857058352a3a8f6d9a617a4999f6aed1bee4edd97d18e7a1f4e4a2318cdf871982415e7dd2b519f498')

build() {
    cd "inputstream.adaptive-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "inputstream.adaptive-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
    #sed -i 's|special://home/cdm|/usr/lib/kodi/addons/inputstream.adaptive/lib|g' "$pkgdir/usr/share/kodi/addons/inputstream.adaptive/resources/settings.xml"
}
