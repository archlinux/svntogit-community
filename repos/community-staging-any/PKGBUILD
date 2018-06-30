# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Carl George < arch at cgtx dot us >

pkgbase=python-click
pkgname=("python-click" "python2-click")
_realname=click
pkgver=6.7
pkgrel=2
pkgdesc="A simple wrapper around optparse for powerful command line utilities"
arch=("any")
url="http://click.pocoo.org/"
license=("BSD")
makedepends=("python-setuptools" "python2-setuptools")
source=("https://github.com/pallets/click/archive/${pkgver}.tar.gz")
sha512sums=('0d582ec4ecf8e4cf9ce2b9eec9d150e047512e1ebdb709eb031599c8e4a9632121dbb809bc1cfe597dd0ba62a9b8a5663c6dfbe41d575a991d27bca6b26130db')

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
