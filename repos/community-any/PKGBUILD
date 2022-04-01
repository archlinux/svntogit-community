# Maintainer: Sven-Hendrik Haase <svenstaro@archlinux.org>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Carl George < arch at cgtx dot us >

pkgname=python-click
_realname=click
pkgver=8.1.2
pkgrel=1
pkgdesc="Simple wrapper around optparse for powerful command line utilities"
arch=("any")
url='https://click.palletsprojects.com/'
license=("BSD")
depends=("python")
makedepends=('python-setuptools' 'python-build' 'python-installer' 'python-wheel')
checkdepends=('python-pytest')
source=("https://github.com/pallets/click/archive/${pkgver}/$pkgname-$pkgver.tar.gz")
sha512sums=('8781965212a0732990e47050db8ae5e37633986b23cd7895d74f06007c61993f8ea45183376761987931caf00dd68c22900bc8d3930d4416853374cfd170a0e5')

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
