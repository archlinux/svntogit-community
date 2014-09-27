# vim:set ft=sh:
# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: (sirocco AT ngs.ru)

pkgbase=doublecmd
pkgname=('doublecmd-gtk2' 'doublecmd-qt')
pkgver=0.5.11
_helpver=0.5.5
pkgrel=1
url="http://doublecmd.sourceforge.net/"
arch=('i686' 'x86_64')
license=('GPL')
install="$pkgbase.install"
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

build() {
	cp -a $pkgbase-$pkgver $pkgbase-gtk
	cp -a $pkgbase-$pkgver $pkgbase-qt

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
	depends=('gtk2')
	conflicts=('doublecmd-qt')
	cd "$srcdir/$pkgbase-gtk"
	./install/linux/install.sh --install-prefix="$pkgdir"

	# install doc
	cd "$srcdir/$pkgbase-help-$_helpver"
	cp -a * "$pkgdir/usr/share/$pkgbase/doc/"
}

package_doublecmd-qt() {
	pkgdesc="twin-panel (commander-style) file manager (QT)"
	depends=('qt4pas')
	conflicts=('doublecmd-gtk2')
	cd "$srcdir/$pkgbase-qt"
	./install/linux/install.sh --install-prefix="$pkgdir"

	# install doc
	cd "$srcdir/$pkgbase-help-$_helpver"
	cp -a * "$pkgdir/usr/share/$pkgbase/doc/"
}

sha256sums=('a7d31243f9e8fc69ed6854a264d78ee59bfe3dd89e2bb19043c715e3b3d114ea'
            '5c5d00187df811df0734bf751a581bce7e1bdd4cf4639b2a1101f1da8743daaf'
            '16560ad7403ffbee1800384768828e1fad924d03068c6248b68a78c393fc4e20')
