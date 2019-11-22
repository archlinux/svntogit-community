# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Cedric Girard <cgirard.archlinux@valinor.fr>
# Contributor: kevku <kevku@gmx.com>

pkgname=kodi-addon-inputstream-adaptive
pkgver=2.4.2
_codename=Leia
pkgrel=4
pkgdesc="InputStream client for adaptive streams for Kodi 18+"
arch=('x86_64')
url="https://github.com/peak3d/inputstream.adaptive"
license=('GPL2')
groups=('kodi-addons' 'kodi-addons-inputstream')
depends=('kodi' 'kodi-platform')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/peak3d/inputstream.adaptive/archive/$pkgver-$_codename.tar.gz")
sha512sums=('218be820b4e7f05d9a3ffd330db785997afe225a994ed4187a1aaa13b28189453d4a82e3553210613aa644f9f98b30bfc7bc048a1ad9674521053ef21e2e26e0')

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
