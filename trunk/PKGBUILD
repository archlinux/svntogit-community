# Maintainer: Joel Teichroeb <joel@teichroeb.net>

pkgname=weston
pkgver=1.0.4
pkgrel=1
pkgdesc="A modern display server."
arch=(i686 x86_64)
url="http://wayland.freedesktop.org"
license=('MIT')
depends=('libxkbcommon' 'wayland' 'libegl-wayland' 'cairo-gl' 'poppler-glib' 'mtdev' 'libxcursor' 'glu' 'libgles')
source=(http://wayland.freedesktop.org/releases/${pkgname}-${pkgver}.tar.xz)
sha1sums=(6f51fe78151ba2854f6cf6a41244c34f39c1d6de)
options=(!libtool)

build() {
	cd ${srcdir}/${pkgname}-${pkgver}
	./configure --prefix=/usr
	make
}

package() {
	cd ${srcdir}/${pkgname}-${pkgver}
	make DESTDIR="${pkgdir}" install

	install -m 755 -D src/weston "${pkgdir}/usr/bin/weston"

	install -m 755 -D clients/clickdot "${pkgdir}/usr/bin/weston-clickdot"
	install -m 755 -D clients/dnd "${pkgdir}/usr/bin/weston-dnd"
	install -m 755 -D clients/editor "${pkgdir}/usr/bin/weston-editor"
	install -m 755 -D clients/eventdemo "${pkgdir}/usr/bin/weston-eventdemo"
	install -m 755 -D clients/flower "${pkgdir}/usr/bin/weston-flower"
	install -m 755 -D clients/gears "${pkgdir}/usr/bin/weston-gears"
	install -m 755 -D clients/image "${pkgdir}/usr/bin/weston-image"
	install -m 755 -D clients/resizor "${pkgdir}/usr/bin/weston-resizor"
	install -m 755 -D clients/simple-egl "${pkgdir}/usr/bin/weston-simple-egl"
	install -m 755 -D clients/simple-shm "${pkgdir}/usr/bin/weston-simple-shm"
	install -m 755 -D clients/simple-touch "${pkgdir}/usr/bin/weston-simple-touch"
	install -m 755 -D clients/smoke "${pkgdir}/usr/bin/weston-smoke"
	install -m 755 -D clients/view "${pkgdir}/usr/bin/weston-view"
}
