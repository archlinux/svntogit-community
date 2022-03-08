# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>

_pyname=frozenlist
pkgname=python-${_pyname}
pkgver=1.3.0
pkgrel=1
pkgdesc='FrozenList is a list-like structure which can be made immutable'
url='https://github.com/aio-libs/frozenlist'
arch=('x86_64')
license=('Apache')
depends=('python')
makedepends=('python-setuptools' 'cython')
checkdepends=('python-pytest' 'python-pytest-cov' 'python-pytest-runner')
source=(${url}/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('780f0ec0e1a701b009e5afcd7f62b2950eda5365140ad5842c09db85b0a3cf282ab70ff9ba752ea6dc7a97542fc7399023aaaca8fdd8ecbd5c26bf64f305f5f4')
b2sums=('d09e18455893f7ede59c37a080e79ea5e085cc3362e53bc7016db64338b2cf26baf44e95ec0c691535527b0eef4a40ec1fbe814e5d4ae238300125438d21b467')

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
  local _python_version=$(python -c 'import sys; print(".".join(map(str, sys.version_info[:2])))')
  PYTHONPATH="$PWD/build/lib.linux-$CARCH-${_python_version}" pytest
}

package() {
  cd "${_pyname}-${pkgver}"
  python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -Dm 644 CHANGES.rst README.rst -t "${pkgdir}/usr/share/doc/${pkgname}"
}

# vim: ts=2 sw=2 et:
