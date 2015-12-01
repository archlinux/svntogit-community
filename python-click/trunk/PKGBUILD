# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Carl George < arch at cgtx dot us >

pkgbase=python-click
pkgname=("python-click" "python2-click")
_realname=click
pkgver=6.2
pkgrel=1
pkgdesc="A simple wrapper around optparse for powerful command line utilities"
arch=("any")
url="http://click.pocoo.org/"
license=("BSD")
makedepends=("python-setuptools" "python2-setuptools")
source=("https://pypi.python.org/packages/source/c/$_realname/$_realname-$pkgver.tar.gz")
sha256sums=('fba0ff70f5ebb4cebbf64c40a8fbc222fb7cf825237241e548354dabe3da6a82')

prepare() {
    cp -a $_realname-$pkgver{,-python2}
}

build() {
    cd "${srcdir}/${_realname}-${pkgver}"
    python setup.py build

    cd "${srcdir}/${_realname}-${pkgver}-python2"
    python2 setup.py build
}

package_python-click() {
    depends=("python")
    cd "${srcdir}/${_realname}-${pkgver}"
    python setup.py install --skip-build --root="${pkgdir}" --optimize=1
    install -Dm644 "LICENSE" "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}

package_python2-click() {
    depends=("python2")
    cd "${srcdir}/${_realname}-${pkgver}-python2"
    python2 setup.py install --skip-build --root="${pkgdir}" --optimize=1
    install -Dm644 "LICENSE" "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
