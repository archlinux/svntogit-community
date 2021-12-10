# Maintainer: Konstantin Gizdov <arch at kge dot pw>
# Contributor: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Contributor: Immae

pkgname=python-pybtex-docutils
pkgver=1.0.1
pkgrel=3
pkgdesc="A docutils backend for pybtex"
arch=("any")
url="https://github.com/mcmtroffaes/pybtex-docutils"
license=("MIT")
depends=('python-six' 'python-docutils' 'python-pybtex')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("https://pypi.io/packages/source/p/pybtex-docutils/pybtex-docutils-$pkgver.tar.gz")
sha256sums=('d53aa0c31dc94d61fd30ea3f06c749e6f510f9ff0e78cb2765a9300f173d8626')

build() {
  cd "${srcdir}/pybtex-docutils-${pkgver}"
  python setup.py build
}

check() {
  cd "${srcdir}/pybtex-docutils-${pkgver}"
  export PYTHONPATH="${srcdir}/pybtex-docutils-${pkgver}:${srcdir}/pybtex-docutils-${pkgver}/src"
  pytest
}

package() {
  cd "${srcdir}/pybtex-docutils-${pkgver}"
  python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
  install -Dm644 LICENSE.rst "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
