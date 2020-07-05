# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Maintainer: Christian Hesse <mail@eworm.de>

pkgname=yubico-c
_shortname=libyubikey
pkgver=1.13
pkgrel=6
pkgdesc='Yubico YubiKey C library'
arch=('x86_64')
url='https://github.com/Yubico/yubico-c'
license=('BSD')
depends=('curl' 'libusb')
provides=("${_shortname}")
conflicts=("${_shortname}")
validpgpkeys=('0A3B0262BCA1705307D5FF06BCA00FD4B2168C0A') # Klas Lindfors <klas@yubico.com>
source=("https://developers.yubico.com/${pkgname}/Releases/${_shortname}-${pkgver}.tar.gz"{,.sig})
sha256sums=('04edd0eb09cb665a05d808c58e1985f25bb7c5254d2849f36a0658ffc51c3401'
            'SKIP')

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

	install -D -m0644 COPYING "${pkgdir}/usr/share/licenses/yubico-c/COPYING"
	install -D -m0644 README "${pkgdir}/usr/share/doc/yubico-c/README"
	make DESTDIR="${pkgdir}/" install
}

