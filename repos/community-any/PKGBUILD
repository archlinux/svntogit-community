# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Matthew Bowra-Dean <matthew@ijw.co.nz>
pkgname=openra
pkgver=20110906
pkgrel=1
pkgdesc="An open-source implementation of the Red Alert engine using .NET/mono and OpenGL"
arch=('any')
url="http://open-ra.org"
license=('GPL3')
install=openra.install
depends=('mono' 'openal' 'mesa' 'freetype2' 'sdl')
makedepends=('git' 'unzip')
optdepends=('nvidia-cg-toolkit: for using the alternative Cg renderer')
options=(!strip)
source=("https://github.com/OpenRA/OpenRA/zipball/release-$pkgver")
md5sums=('78389e52dca9144a30b658d74edd1d61')

build() {
    unzip -f release-$pkgver
    cd OpenRA-OpenRA-*

    sed -i "s|prefix = .*|prefix = /usr|g" Makefile
    make
}

package() {
    cd OpenRA-OpenRA-*

    mkdir -p "$pkgdir/usr/share/applications"
    sed "s/{VERSION}/$pkgver/g" packaging/linux/openra.desktop > "$pkgdir/usr/share/applications/openra.desktop"

    mkdir -p "$pkgdir/usr/share/icons/"
    cp -r packaging/linux/hicolor "$pkgdir/usr/share/icons/"

    make DESTDIR="$pkgdir" install

    find "$pkgdir" -iname \*.mdb -delete

    mv "$pkgdir/usr/share/openra/thirdparty/Tao/"* "$pkgdir/usr/share/openra/"
    rm -r "$pkgdir/usr/share/openra/thirdparty"
}
