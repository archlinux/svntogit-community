# Maintainer: Christian Hesse <mail@eworm.de>

pkgname=yubico-c-client
_shortname=ykclient
pkgver=2.15
pkgrel=5
pkgdesc='Yubico YubiKey client C library'
arch=('x86_64')
url='https://github.com/Yubico/yubico-c-client'
license=('BSD')
depends=('curl' 'yubico-c')
makedepends=('help2man')
provides=("${_shortname}")
conflicts=("${_shortname}")
validpgpkeys=('0A3B0262BCA1705307D5FF06BCA00FD4B2168C0A') # Klas Lindfors <klas@yubico.com>
source=("https://developers.yubico.com/${pkgname}/Releases/${_shortname}-${pkgver}.tar.gz"{,.sig}
        '0001-https-ify-urls-and-drop-v1-selftest.patch')
sha256sums=('f461cdefe7955d58bbd09d0eb7a15b36cb3576b88adbd68008f40ea978ea5016'
            'SKIP'
            'a1df5f6134b03bd2cd62c68815b424797980c1a7cefdf1a72f87b9b41d6dc525')

prepare() {
	cd "${_shortname}-${pkgver}"

	patch -Np1 < ../0001-https-ify-urls-and-drop-v1-selftest.patch
}

build() {
	cd "${_shortname}-${pkgver}"

	./configure \
		--prefix=/usr
	make
}

check() {
	cd "${_shortname}-${pkgver}"

	make check
}

package() {
	cd "${_shortname}-${pkgver}"

	install -D -m0644 COPYING "${pkgdir}/usr/share/licenses/yubico-c-client/COPYING"
	install -D -m0644 README "${pkgdir}/usr/share/doc/yubico-c-client/README"
	make DESTDIR="${pkgdir}/" install
}

