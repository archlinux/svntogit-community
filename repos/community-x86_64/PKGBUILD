# Maintainer: Daniel Bermond <dbermond@archlinux.org>

pkgname=mujs
pkgver=1.1.1
pkgrel=1
pkgdesc='An embeddable Javascript interpreter in C'
arch=('x86_64')
url='https://mujs.com/'
license=('ISC')
depends=('readline')
source=("https://github.com/ccxvii/mujs/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz"
        '010-mujs-use-arch-flags.patch')
sha256sums=('ade588c10e1cbed1eaca933a89f3199a1e6b826a6a00b48dc29b99630f017764'
            'aa60ade4da8d0ef5261bf6c2e73b170ba47931ae6fc2cad61b5959cdb780c744')

prepare() {
    patch -d "${pkgname}-${pkgver}" -Np1 -i "${srcdir}/010-mujs-use-arch-flags.patch"
}

build() {
    make -C "${pkgname}-${pkgver}" release shared
}

package() {
    make -C "${pkgname}-${pkgver}" DESTDIR="$pkgdir" prefix='/usr' install-shared
    install -D -m644 "${pkgname}-${pkgver}/docs"/* -t "${pkgdir}/usr/share/doc/${pkgname}"
    install -D -m644 "${pkgname}-${pkgver}/COPYING" "${pkgdir}/usr/share/licenses/mujs/LICENSE"
}
