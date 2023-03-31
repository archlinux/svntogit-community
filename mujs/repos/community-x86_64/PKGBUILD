# Maintainer: Daniel Bermond <dbermond@archlinux.org>

pkgname=mujs
pkgver=1.3.3
pkgrel=1
pkgdesc='An embeddable Javascript interpreter in C'
arch=('x86_64')
url='https://mujs.com/'
license=('ISC')
depends=('readline')
source=("https://github.com/ccxvii/mujs/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz"
        '010-mujs-use-arch-flags.patch')
sha256sums=('e2c5ee5416dfda2230c7a0cb7895df9a9b2d5b2065bb18e7e64dec2a796abe1b'
            'a122d4a059faf99ea864ebd4cd82df7a26e223280bf985913958013f93b2860f')

prepare() {
    patch -d "${pkgname}-${pkgver}" -Np1 -i "${srcdir}/010-mujs-use-arch-flags.patch"
}

build() {
    make -C "${pkgname}-${pkgver}" prefix='/usr' release
}

package() {
    make -C "${pkgname}-${pkgver}" DESTDIR="$pkgdir" prefix='/usr' install-common install-shared
    install -D -m644 "${pkgname}-${pkgver}/docs"/* -t "${pkgdir}/usr/share/doc/${pkgname}"
    install -D -m644 "${pkgname}-${pkgver}/COPYING" "${pkgdir}/usr/share/licenses/mujs/LICENSE"
}
