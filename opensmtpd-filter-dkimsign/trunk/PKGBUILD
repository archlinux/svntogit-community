# Maintainer: Bruno Pagani <archange@archlinux.org>
# Contributor: Maarten de Vries <maarten@de-vri.es>

_pkg=filter-dkimsign
pkgname=opensmtpd-${_pkg}
pkgver=0.6
pkgrel=1
pkgdesc="OpenSMTPD filter for signing mail with DKIM"
license=(BSD)
url="https://imperialat.at/dev/filter-dkimsign/"
arch=(x86_64)
depends=(libopensmtpd openssl)
makedepends=(gzip mandoc)
source=(https://imperialat.at/releases/${_pkg}-${pkgver}.tar.gz
        LICENSE)
sha512sums=('1efab386a020c6a3cbf6059ce0feea539fa62be0990fd8538c4b152fa0c302d7bfffa7c7bb74643c25e47c20250f600f1371d2725dc3178ad103ce585530c0ce'
            '24ffeb515e767416728adf4f02aac9b6305447ff4ce8acdfb1ecb8321f76e261e5a536b20df9acec90542e3c3f30e259c0d11cd99d401eb154fd5faf89a6e125')

build() {
  cd ${_pkg}-${pkgver}
  make -f Makefile.gnu
}

package() {
  cd ${_pkg}-${pkgver}
  make -f Makefile.gnu BINDIR=/usr/lib/smtpd/opensmtpd/ DESTDIR="${pkgdir}" install
  install -Dm644 ../LICENSE -t "${pkgdir}"/usr/share/licenses/${pkgname}/
}
