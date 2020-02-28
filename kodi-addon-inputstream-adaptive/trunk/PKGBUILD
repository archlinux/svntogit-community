# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Cedric Girard <cgirard.archlinux@valinor.fr>
# Contributor: kevku <kevku@gmx.com>

pkgname=kodi-addon-inputstream-adaptive
pkgver=2.4.3
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
sha512sums=('832e8501294cd8abb253eb05e22525476517252c9b3012a4b86973f9ea79e31f21be4f9967ba3c7c29da157cae72eb4dd7481ea95f5a9ab9f96cf994c36198f1')

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
