# Maintainer: Daniel Bermond <dbermond@archlinux.org>

pkgname=mujs
pkgver=1.0.6
pkgrel=1
pkgdesc='An embeddable Javascript interpreter in C'
arch=('x86_64')
url='https://mujs.com/'
license=('ISC')
depends=('readline')
source=("${pkgname}-${pkgver}.tar.gz"::"https://github.com/ccxvii/mujs/archive/${pkgver}.tar.gz"
        '010-mujs-use-arch-flags.patch')
sha256sums=('a444d8ea22b18eff89acbc7f9e45cc95e5b63b30ae8f4b8000b858cd17006f2d'
            '051c8a8727f4ff2816e9c060fbe969b7d1e8b9e2c07d704e809c24ff4394f0f4')

prepare() {
    patch -d "${pkgname}-${pkgver}" -Np1 -i "${srcdir}/010-mujs-use-arch-flags.patch"
}

build() {
    make -C "${pkgname}-${pkgver}" release
}

package() {
    mkdir -p "${pkgdir}/usr/share/doc/${pkgname}"
    
    make -C "${pkgname}-${pkgver}" DESTDIR="$pkgdir" prefix='/usr' install-shared
    
    install -D -m644 "${pkgname}-${pkgver}/COPYING" "${pkgdir}/usr/share/licenses/mujs/LICENSE"
    install    -m644 "${pkgname}-${pkgver}/docs/"*  "${pkgdir}/usr/share/doc/${pkgname}"
}
