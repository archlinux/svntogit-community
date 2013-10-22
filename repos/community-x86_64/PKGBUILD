# vim:set ft=sh:
# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: (sirocco AT ngs.ru)

pkgbase=doublecmd
pkgname=('doublecmd-gtk2' 'doublecmd-qt')
pkgver=0.5.7
_helpver=0.5.5
pkgrel=2
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
sha256sums=('8e2059f986fff26da5d7b98af95be64b12c5cef6b50fe3cacd9a2805947aa343'
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
	conflicts=('doublecmd-qt')
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
	conflicts=('doublecmd-gtk2')
	cd "$srcdir/$pkgbase-qt"
	sed -e 's/LIB_SUFFIX=.*/LIB_SUFFIX=/g' -i ./install/linux/install.sh
	./install/linux/install.sh --install-prefix="$pkgdir"

	# install doc
	cd "$srcdir/$pkgbase-help-$_helpver"
	cp -a * "$pkgdir/usr/share/$pkgbase/doc/"
}

