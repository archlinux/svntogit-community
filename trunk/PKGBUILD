# vim:set ft=sh:
# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: (sirocco AT ngs.ru)

pkgbase=doublecmd
pkgname=('doublecmd-gtk2' 'doublecmd-qt')
pkgver=0.7.1
_helpver=0.6.0
pkgrel=2
url="http://doublecmd.sourceforge.net/"
arch=('i686' 'x86_64')
license=('GPL')
provides=("$pkgbase")
makedepends=('lazarus' 'qt4pas' 'gtk2')
optdepends=(
	'lua51: scripting'
	'p7zip: support for 7zip archives'
	'libunrar: support for rar archives'
)
source=(
	"http://downloads.sourceforge.net/project/$pkgbase/Double%20Commander%20Source/$pkgbase-$pkgver-src.tar.gz"
	"http://downloads.sourceforge.net/project/$pkgbase/Double%20Commander%20Source/$pkgbase-help-$_helpver-src.tar.gz"
	"http://www.herecura.be/files/lazarus-20140321-2.tar.gz"
)
sha256sums=('ecfe1fe8d6026181ae03a3defa4ec73226844a2bca8935bab1b66cc2c604fbbf'
            'd50a58f0e8c25c07720f2afd987213f330dfce268e2aef349d1da3de2eef1c39'
            '16560ad7403ffbee1800384768828e1fad924d03068c6248b68a78c393fc4e20')

prepare() {
	cd "$pkgbase-$pkgver"
	sed -e 's/LIB_SUFFIX=.*/LIB_SUFFIX=/g' -i install/linux/install.sh

	cd "$srcdir"

	cp -a "$pkgbase-$pkgver" "$pkgbase-gtk"
	cp -a "$pkgbase-$pkgver" "$pkgbase-qt"
}

build() {
	msg2 'build gtk'
	gtkdir="$srcdir/$pkgbase-gtk"
	cd "$gtkdir"
	bsdtar -zxf "$srcdir/lazarus-20140321-2.tar.gz"
	sed -e "s/\\(export\\ lazbuild=\\).*/\\1\"\$(which lazbuild) --primary-config-path=${gtkdir//\//\\\/}\/lazarus\/lazarus-$CARCH\"/" -i build.sh
	sed -e "s/%%SRCDIR%%/${gtkdir//\//\\\/}/g" -i lazarus/packagefiles.xml
	./build.sh beta gtk2

	msg2 'build qt'
	qtdir="$srcdir/$pkgbase-qt"
	cd "$qtdir"
	bsdtar -zxf "$srcdir/lazarus-20140321-2.tar.gz"
	sed -e "s/\\(export\\ lazbuild=\\).*/\\1\"\$(which lazbuild) --primary-config-path=${qtdir//\//\\\/}\/lazarus\/lazarus-$CARCH\"/" -i build.sh
	sed -e "s/%%SRCDIR%%/${qtdir//\//\\\/}/g" -i lazarus/packagefiles.xml
	./build.sh beta qt

}

package_doublecmd-gtk2() {
	pkgdesc="twin-panel (commander-style) file manager (GTK)"
	depends=('gtk2' 'desktop-file-utils' 'hicolor-icon-theme' 'shared-mime-info')
	conflicts=('doublecmd-qt')
	cd "$srcdir/$pkgbase-gtk"
	./install/linux/install.sh --install-prefix="$pkgdir"

	# install doc
	cd "$srcdir/$pkgbase-help-$_helpver"
	cp -a * "$pkgdir/usr/share/$pkgbase/doc/"
}

package_doublecmd-qt() {
	pkgdesc="twin-panel (commander-style) file manager (QT)"
	depends=('qt4pas' 'desktop-file-utils' 'hicolor-icon-theme' 'shared-mime-info')
	conflicts=('doublecmd-gtk2')
	cd "$srcdir/$pkgbase-qt"
	./install/linux/install.sh --install-prefix="$pkgdir"

	# install doc
	cd "$srcdir/$pkgbase-help-$_helpver"
	cp -a * "$pkgdir/usr/share/$pkgbase/doc/"
}

