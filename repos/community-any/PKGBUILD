# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: Carl George < arch at cgtx dot us >

pkgname=python-click
_realname=click
pkgver=8.0.2
pkgrel=1
pkgdesc="A simple wrapper around optparse for powerful command line utilities"
arch=("any")
url="http://click.pocoo.org/"
license=("BSD")
depends=("python")
makedepends=("python-setuptools")
source=("https://github.com/pallets/click/archive/${pkgver}/$pkgname-$pkgver.tar.gz")
sha512sums=('473184751fde7a09b0730e84db2204fa3bc72d583e0edf5a2897a4bae8f1d2ffdf01c69ae971d9158cc59d22eb852eb83f28428a2635a95c43596abbc9257891')

build() {
    cd "${srcdir}/${_realname}-${pkgver}"
    python setup.py build
}

package() {
    cd "${srcdir}/${_realname}-${pkgver}"
    python setup.py install --skip-build --root="${pkgdir}" --optimize=1
    install -Dm644 "LICENSE.rst" "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE.rst"
}
