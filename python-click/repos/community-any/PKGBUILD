# Maintainer: Sven-Hendrik Haase <svenstaro@archlinux.org>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Carl George < arch at cgtx dot us >

pkgname=python-click
_realname=click
pkgver=8.1.0
pkgrel=2
pkgdesc="Simple wrapper around optparse for powerful command line utilities"
arch=("any")
url='https://click.palletsprojects.com/'
license=("BSD")
depends=("python")
makedepends=('python-setuptools' 'python-build' 'python-installer' 'python-wheel')
checkdepends=('python-pytest')
source=("https://github.com/pallets/click/archive/${pkgver}/$pkgname-$pkgver.tar.gz")
sha512sums=('7d9fcd74392baa55e0fd9050e7382d4b8b542856d4fee79ec5a4d6185ddeb47abaed1de6771e30aaec6cee5cff7166dd8ab7fefbc6aefa1856adc58b9fecc0c7')

build() {
  cd "${srcdir}/${_realname}-${pkgver}"
  python -m build --wheel --no-isolation
}

check() {
  cd "${srcdir}/${_realname}-${pkgver}"
  PYTHONPATH="build/lib" pytest
}

package() {
  cd "${srcdir}/${_realname}-${pkgver}"
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm 644 "LICENSE.rst" -t "${pkgdir}/usr/share/licenses/${pkgname}"
}

# vim:set ts=2 sw=2 et:
