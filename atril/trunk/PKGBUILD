# Maintainer: Alexander Epaneshnikov <alex19ep@archlinux.org>
# Contributor: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=atril
pkgver=1.26.1
pkgrel=1
pkgdesc="MATE document viewer"
url="https://mate-desktop.org"
arch=('x86_64')
license=('GPL')
depends=('djvulibre' 'libspectre' 'libgxps' 'mathjax2' 'gettext' 'poppler-glib' 'cairo>=1.14.0' 'webkit2gtk>=2.6.0' 'libsynctex')
makedepends=('caja' 'gobject-introspection' 'itstool' 'texlive-bin')
optdepends=('caja: Document Properties extension'
            'texlive-bin: DVI support')
groups=('mate-extra')
conflicts=('atril-gtk3')
replaces=('atril-gtk3')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/$pkgname-$pkgver.tar.xz")
sha256sums=('a53a613acb9701a18ad671bf590254d1ce836ba0ae1be2c0bd8948fdf6b491a4')

prepare() {
	cd "$pkgname-$pkgver"

	# Fix mathjax path
	sed -i 's|/usr/share/javascript/mathjax|/usr/share/mathjax2|' backend/epub/epub-document.c
}

build() {
	cd "$pkgname-$pkgver"
	./configure \
        	--prefix=/usr \
        	--libexecdir=/usr/lib/${_pkgbase} \
        	--enable-djvu \
        	--enable-dvi \
        	--enable-epub \
        	--enable-t1lib \
        	--enable-pixbuf \
        	--enable-comics \
        	--enable-xps \
        	--enable-introspection

    	#https://bugzilla.gnome.org/show_bug.cgi?id=656231
    	sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool

    	make
}

package() {
    	cd "$pkgname-$pkgver"
    	make DESTDIR="$pkgdir" install
}
