# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Kevin Piche <kevin@archlinux.org>
# Contributor: Tom Newsom <Jeepster@gmx.co.uk>
# vim: set ft=sh:

pkgname=fwbuilder
pkgver=5.3.6
pkgrel=2
pkgdesc="Object-oriented GUI and set of compilers for various firewall platforms"
url="http://www.fwbuilder.org/"
arch=('i686' 'x86_64')
license=('GPL')
depends=('libxslt' 'net-snmp' 'qt5-base' 'desktop-file-utils' 'hicolor-icon-theme' 'shared-mime-info')
conflicts=('libfwbuilder')
source=(
    "$pkgname-$pkgver.tar.gz::https://github.com/UNINETT/$pkgname/archive/v$pkgver.tar.gz"
    'fwbuilder.xml'
    'iosimporter.patch'
    'routingcompileropenbsd.patch'
    'fixes-5.3.6.patch'
)
sha256sums=('672c2870c3a2ce1eb504a97d17ea9a8eb6dd61ec314cf79b9488b48a356cdfa6'
            'f8eacaa9895b17af3a1c148064b5ad8381b83f7983acb14687faef488ac8fede'
            '7ceff7cb70828864831bbb6a438a14fd08b198bb8fc21f736fcac4ec81eca970'
            '6bd0fe7a06acad4d6ef40451319ca87b874935552f7fbcffba977a1bc51114f5'
            'd1ce4860db3d83273248adc7f5751d4c69ddd8bad2ce997453bcf7b38662c18d')

build() {
    cd "$pkgname-$pkgver"
    find -name "qmake.inc.in" -exec sed -e 's/\/usr\/include//g' -i {} \;
    patch -p0 -i "$srcdir/iosimporter.patch"
    patch -p0 -i "$srcdir/routingcompileropenbsd.patch"
    patch -p1 -i "$srcdir/fixes-5.3.6.patch"
    ./autogen.sh --prefix=/usr
    make
}

package() {
    cd "$pkgname-$pkgver"
    make INSTALL_ROOT="${pkgdir}" install
    echo "MimeType=text/x-xml-fwbuilder;" >> "$pkgdir/usr/share/applications/${pkgname}.desktop"
    install -Dm644 "$srcdir/fwbuilder.xml" "$pkgdir/usr/share/mime/packages/fwbuilder.xml"
}
