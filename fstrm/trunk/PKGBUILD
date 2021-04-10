# Maintainer: Bruno Pagani <archange@archlinux.org>

pkgname=fstrm
pkgver=0.6.1
pkgrel=1
pkgdesc="C implementation of the Frame Streams data transport protocol"
arch=(x86_64)
url="https://github.com/farsightsec/fstrm"
license=(Apache)
depends=(libevent)
source=(${url}/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha256sums=('4f0f7ad2b760119c441aba58271e84de683b3cc138530d02710896641866e2d2')

prepare() {
	cd ${pkgname}-${pkgver}
    autoreconf -vfi
}

build() {
	cd ${pkgname}-${pkgver}
	./configure --prefix=/usr
	make
}

check() {
	cd ${pkgname}-${pkgver}
	make -k check
}

package() {
	cd ${pkgname}-${pkgver}
	make DESTDIR="${pkgdir}" install
	install -Dm644 LICENSE -t "${pkgdir}"/usr/share/licenses/${pkgname}/
}
