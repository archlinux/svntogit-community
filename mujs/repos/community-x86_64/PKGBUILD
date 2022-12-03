# Maintainer: Daniel Bermond <dbermond@archlinux.org>

pkgname=mujs
pkgver=1.3.2
pkgrel=1
pkgdesc='An embeddable Javascript interpreter in C'
arch=('x86_64')
url='https://mujs.com/'
license=('ISC')
depends=('readline')
source=("https://github.com/ccxvii/mujs/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz"
        '010-mujs-use-arch-flags.patch')
sha256sums=('59763cc32776714b4f00a0efede83f4f56b381c9dbaced4756d665c214249dca'
            '83d67d384e27f285f128034a6c732dff97eeda47d141db83836e6ce70d4db9fd')

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
