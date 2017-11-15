# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Kevin Piche <kevin@archlinux.org>
# Contributor: Tom Newsom <Jeepster@gmx.co.uk>
# vim: set ft=sh:

pkgname=fwbuilder
pkgver=5.3.7
pkgrel=1
pkgdesc="Object-oriented GUI and set of compilers for various firewall platforms"
url="https://github.com/fwbuilder"
arch=('x86_64')
license=('GPL')
depends=('libxslt' 'net-snmp' 'qt5-base' 'desktop-file-utils' 'hicolor-icon-theme' 'shared-mime-info')
conflicts=('libfwbuilder')
source=(
    "$pkgname-$pkgver.tar.gz::https://github.com/$pkgname/$pkgname/archive/v$pkgver.tar.gz"
    'fwbuilder.xml'
)
sha256sums=('aba1ed8f690e9e4659c0e981120ea68da7ee327d6cf81260d51329351addf91e'
            'f8eacaa9895b17af3a1c148064b5ad8381b83f7983acb14687faef488ac8fede')

build() {
    cd "$pkgname-$pkgver"
    find -name "qmake.inc.in" -exec sed -e 's/\/usr\/include//g' -i {} \;
    ./autogen.sh --prefix=/usr
    make
}

package() {
    cd "$pkgname-$pkgver"
    make INSTALL_ROOT="${pkgdir}" install
    echo "MimeType=text/x-xml-fwbuilder;" >> "$pkgdir/usr/share/applications/${pkgname}.desktop"
    install -Dm644 "$srcdir/fwbuilder.xml" "$pkgdir/usr/share/mime/packages/fwbuilder.xml"
}
