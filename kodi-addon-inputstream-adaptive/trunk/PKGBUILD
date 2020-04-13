# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Cedric Girard <cgirard.archlinux@valinor.fr>
# Contributor: kevku <kevku@gmx.com>

pkgname=kodi-addon-inputstream-adaptive
pkgver=2.4.4
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
sha512sums=('5ddc8ee08144f43369d807b1a8a2b1fc2fa70a3a0063be09a47d1df021442f0a7fb46acf2399e458bb807429f38abe9bdea5b4994ab58f93f07214b330e150f2')

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
