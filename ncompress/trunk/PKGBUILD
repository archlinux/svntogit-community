# Maintainer: Eli Schwartz <eschwartz@archlinux.org>

pkgname=ncompress
pkgver=5.0
pkgrel=2
pkgdesc="a fast, simple LZW file compressor"
arch=('x86_64')
url="https://github.com/vapier/${pkgname}"
license=('custom:PublicDomain')
depends=('glibc')
provides=('compress')
source=("${pkgname}-${pkgver}.tar.gz::${url}/archive/v${pkgver}.tar.gz")
sha256sums=('96ec931d06ab827fccad377839bfb91955274568392ddecf809e443443aead46')
b2sums=('7b296bd00024bfb483d3261ff8aa6e47a6be8c62b445c3d456d702b69fbc2a7b731326f7ea91aa331ba8e8a27936f4318b3e252cc978b6bf3198e8812988913f')

build() {
    cd ${pkgname}-${pkgver}

    make
}

package() {
    cd ${pkgname}-${pkgver}

    make DESTDIR="${pkgdir}" PREFIX=/usr install_core
    # an uncompress implementation which handles gzipped files is provided by gzip
    mv "${pkgdir}"/usr/bin/uncompress{,.real}

    install -Dm644 -t "${pkgdir}/usr/share/licenses/${pkgname}/" LZW.INFO UNLICENSE
}
