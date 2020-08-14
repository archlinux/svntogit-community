# Maintainer:  Martin Wimpress <code@flexion.org>
# Contributor: Gustavo Alvarez <sl1pkn07@gmail.com>
# Contributor: Dirk Berg <berg1981@googlemail.com>

pkgname=libaacs
pkgver=0.11.0
pkgrel=1
pkgdesc="Advanced Access Content System"
arch=('x86_64')
license=('LGPL')
url="https://www.videolan.org/developers/libaacs.html"
depends=('libgcrypt')
source=("ftp://ftp.videolan.org/pub/videolan/${pkgname}/${pkgver}/${pkgname}-${pkgver}.tar.bz2")
sha512sums=('167edbb6f26599e41d6084908039bf902f69f57da1f64f1491734157d1568ad0b32c8ea3064e0706e383af8dc6007eef65170b2b47222bf3d363e395e0b60388')

build() {
    cd "${srcdir}/${pkgname}-${pkgver}"
    ./bootstrap
    ./configure --prefix=/usr
    make
}

package() {
    cd "${srcdir}/${pkgname}-${pkgver}"
    make DESTDIR="${pkgdir}" install
    install -Dm644 KEYDB.cfg "${pkgdir}/usr/share/doc/${pkgname}"/KEYDB.cfg
    install -Dm644 README.md "${pkgdir}/usr/share/doc/${pkgname}"/README.md
}
