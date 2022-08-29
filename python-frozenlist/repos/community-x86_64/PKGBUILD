# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>

_pyname=frozenlist
pkgname=python-${_pyname}
pkgver=1.3.1
pkgrel=1
pkgdesc='FrozenList is a list-like structure which can be made immutable'
url='https://github.com/aio-libs/frozenlist'
arch=('x86_64')
license=('Apache')
depends=('python')
makedepends=('cython' 'python-build' 'python-installer' 'python-wheel' 'python-setuptools')
checkdepends=('python-pytest' 'python-pytest-cov' 'python-pytest-runner')
source=(${url}/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('4986f3635ebd2d3ca9623299a66375b03938a7be72f7a1d3437b1bf8c0739513942e6babf00476b61055c9ebee3638ec807dad521c52990104d4d57017efdfb2')
b2sums=('7428d936926978acb90a857e0f76b303dddea684c3e815b3fd583e888102e114cc629fcd8e862a4e72775f8525193becfd4b9cd844a36f5b2c7964605008bb84')

prepare() {
  cd "${_pyname}-${pkgver}"
  sed 's|.install-cython ||' -i Makefile
}

build() {
  cd "${_pyname}-${pkgver}"
  make cythonize
  python -m build --wheel --no-isolation
}

check() {
  cd "${_pyname}-${pkgver}"
  local _python_version=$(python -c 'import sys; print("".join(map(str, sys.version_info[:2])))')
  PYTHONPATH="$PWD/build/lib.linux-$CARCH-cpython-${_python_version}" pytest
}

package() {
  cd "${_pyname}-${pkgver}"
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -Dm 644 CHANGES.rst README.rst -t "${pkgdir}/usr/share/doc/${pkgname}"
}

# vim: ts=2 sw=2 et:
