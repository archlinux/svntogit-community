# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: Carl George < arch at cgtx dot us >

pkgname=python-click
_realname=click
pkgver=8.0.3
pkgrel=3
pkgdesc="A simple wrapper around optparse for powerful command line utilities"
arch=("any")
url="http://click.pocoo.org/"
license=("BSD")
depends=("python")
makedepends=("python-setuptools")
source=("https://github.com/pallets/click/archive/${pkgver}/$pkgname-$pkgver.tar.gz")
sha512sums=('73d29b73d5f90132282753fa1b53f42a690ebf713e8e4f2e3ff3c8820ef71ed82c5165bf61563341170a263c4202adb5690540fdeb6501fb9d81d2db06a5e89e')

build() {
    cd "${srcdir}/${_realname}-${pkgver}"
    python setup.py build
}

package() {
    cd "${srcdir}/${_realname}-${pkgver}"
    python setup.py install --skip-build --root="${pkgdir}" --optimize=1
    install -Dm644 "LICENSE.rst" "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE.rst"
}
