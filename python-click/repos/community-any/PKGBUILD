# Maintainer: Sven-Hendrik Haase <svenstaro@archlinux.org>
# Contributor: Carl George < arch at cgtx dot us >

pkgname=python-click
_realname=click
pkgver=8.1.0
pkgrel=1
pkgdesc="A simple wrapper around optparse for powerful command line utilities"
arch=("any")
url="http://click.pocoo.org/"
license=("BSD")
depends=("python")
makedepends=("python-setuptools")
source=("https://github.com/pallets/click/archive/${pkgver}/$pkgname-$pkgver.tar.gz")
sha512sums=('7d9fcd74392baa55e0fd9050e7382d4b8b542856d4fee79ec5a4d6185ddeb47abaed1de6771e30aaec6cee5cff7166dd8ab7fefbc6aefa1856adc58b9fecc0c7')

build() {
    cd "${srcdir}/${_realname}-${pkgver}"
    python setup.py build
}

package() {
    cd "${srcdir}/${_realname}-${pkgver}"
    python setup.py install --skip-build --root="${pkgdir}" --optimize=1
    install -Dm644 "LICENSE.rst" "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE.rst"
}
