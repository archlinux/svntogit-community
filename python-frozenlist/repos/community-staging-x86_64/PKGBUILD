# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>

_pyname=frozenlist
pkgname=python-${_pyname}
pkgver=1.2.0
pkgrel=3
pkgdesc='FrozenList is a list-like structure which can be made immutable'
url='https://github.com/aio-libs/frozenlist'
arch=('x86_64')
license=('Apache')
depends=('python')
makedepends=('python-setuptools' 'cython')
checkdepends=('python-pytest' 'python-pytest-cov' 'python-pytest-runner')
source=(${url}/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('e5dda13e173db0b1c6e8c5a61949534f4eb30211cc4fcd102d0be1b55ee48e2db90d52fd770a2c6d6076f3a0d9e11289629a7a115c1270377636eda35d107e7a')
b2sums=('cc82db759906ad3e0be1806cacd6815377f264ed07ed272abb7da4753c11561564cf1cb4dfc0154abaeb4005f5607c26e602410a4ef45dd8e94e26583caa2ab7')

prepare() {
  cd "${_pyname}-${pkgver}"
  sed 's|.install-cython ||' -i Makefile
}

build() {
  cd "${_pyname}-${pkgver}"
  make cythonize
  python setup.py build
}

check() {
  cd "${_pyname}-${pkgver}"
  python setup.py test
}

package() {
  cd "${_pyname}-${pkgver}"
  python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -Dm 644 CHANGES.rst README.rst -t "${pkgdir}/usr/share/doc/${pkgname}"
}

# vim: ts=2 sw=2 et:
