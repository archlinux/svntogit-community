# Maintainer: Sven-Hendrik Haase <svenstaro@archlinux.org>
# Contributor: Carl George < arch at cgtx dot us >

pkgname=python-click
_realname=click
pkgver=8.0.4
pkgrel=1
pkgdesc="A simple wrapper around optparse for powerful command line utilities"
arch=("any")
url="http://click.pocoo.org/"
license=("BSD")
depends=("python")
makedepends=("python-setuptools")
source=("https://github.com/pallets/click/archive/${pkgver}/$pkgname-$pkgver.tar.gz")
sha512sums=('2a572863814ef4f79ee408d4aa8df30a15b958986c4615e13bdeab30b4847679330e1b3baeeeff1aa80464a08418400c7a1ff22f29db4fc8d8042ab7b1ba475c')

build() {
    cd "${srcdir}/${_realname}-${pkgver}"
    python setup.py build
}

package() {
    cd "${srcdir}/${_realname}-${pkgver}"
    python setup.py install --skip-build --root="${pkgdir}" --optimize=1
    install -Dm644 "LICENSE.rst" "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE.rst"
}
