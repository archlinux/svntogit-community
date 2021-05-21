# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: Carl George < arch at cgtx dot us >

pkgname=python-click
_realname=click
pkgver=8.0.1
pkgrel=1
pkgdesc="A simple wrapper around optparse for powerful command line utilities"
arch=("any")
url="http://click.pocoo.org/"
license=("BSD")
depends=("python")
makedepends=("python-setuptools")
source=("https://github.com/pallets/click/archive/${pkgver}/$pkgname-$pkgver.tar.gz")
sha512sums=('d93ec1d070dfa306733ee79893c64de9afcb0c7bf03d3f543dd697ef195f3a750828f77842a22886960a938740b92f0122962076ea52b911b87f7f75941a9032')

build() {
    cd "${srcdir}/${_realname}-${pkgver}"
    python setup.py build
}

package() {
    cd "${srcdir}/${_realname}-${pkgver}"
    export PYTHONHASHSEED=0
    python setup.py install --skip-build --root="${pkgdir}" --optimize=1
    install -Dm644 "LICENSE.rst" "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE.rst"
}
