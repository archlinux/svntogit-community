# vim:set ft=sh:
# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: (sirocco AT ngs.ru)

pkgbase=doublecmd
pkgname=('doublecmd-gtk2' 'doublecmd-qt')
pkgver=0.5.6
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
)
sha256sums=('b909ee5c57cb2803e4393163f5c44513144cb32e304fa2e1dfee6f33d0999bc5'
            '5c5d00187df811df0734bf751a581bce7e1bdd4cf4639b2a1101f1da8743daaf')

build() {
	cp -a $pkgbase-$pkgver $pkgbase-gtk
	cp -a $pkgbase-$pkgver $pkgbase-qt

	cd "$srcdir/$pkgbase-gtk"
	if [ "$CARCH" = "i686" ]; then
		sed -e '/fPIC/d' -i "$srcdir/$pkgbase-gtk/components/doublecmd/doublecmd_common.lpk"
	fi
	sed -e 's/\(export\ lazbuild=\).*/\1"$(which\ lazbuild) --lazarusdir=\/usr\/lib\/lazarus"/' -i build.sh
	./build.sh beta gtk2

	cd "$srcdir/$pkgbase-qt"
	# dont use fPIC on i686
	if [ "$CARCH" = "i686" ]; then
		sed -e '/fPIC/d' -i "$srcdir/$pkgbase-qt/components/doublecmd/doublecmd_common.lpk"
	fi
	sed -e 's/\(export\ lazbuild=\).*/\1"$(which\ lazbuild) --lazarusdir=\/usr\/lib\/lazarus"/' -i build.sh
	./build.sh beta qt
}

package_doublecmd-gtk2() {
	pkgdesc="twin-panel (commander-style) file manager (GTK)"
	depends=('gtk2')
	cd "$srcdir/$pkgbase-gtk"
	sed -e 's/LIB_SUFFIX=.*/LIB_SUFFIX=/g' -i ./install/linux/install.sh
	./install/linux/install.sh --install-prefix="$pkgdir"

	# install doc
	cd "$srcdir/$pkgbase-help-$_helpver"
	cp -a * "$pkgdir/usr/share/$pkgbase/doc/"
}

package_doublecmd-qt() {
	pkgdesc="twin-panel (commander-style) file manager (QT)"
	depends=('qt4pas')
	cd "$srcdir/$pkgbase-qt"
	sed -e 's/LIB_SUFFIX=.*/LIB_SUFFIX=/g' -i ./install/linux/install.sh
	./install/linux/install.sh --install-prefix="$pkgdir"

	# install doc
	cd "$srcdir/$pkgbase-help-$_helpver"
	cp -a * "$pkgdir/usr/share/$pkgbase/doc/"
}

