# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>

_pyname=frozenlist
pkgname=python-${_pyname}
pkgver=1.3.3
pkgrel=2
pkgdesc='FrozenList is a list-like structure which can be made immutable'
url='https://github.com/aio-libs/frozenlist'
arch=('x86_64')
license=('Apache')
depends=('python')
makedepends=('cython' 'python-build' 'python-installer' 'python-wheel' 'python-setuptools')
checkdepends=('python-pytest' 'python-pytest-cov' 'python-pytest-runner')
source=(${url}/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('8f416996c18d352912e88dad6b503cb1e5ce566d69e97aad8d7eedc6415316e8c9e63eb2c341c5d2409ebf90fd58153ce642d5d88f277435bc6e5a4f1ce8b949')
b2sums=('cf0dcd2ed0e22cb7fa3d57a73177e53cace8e6301c462ab56544678f1f78f113ac3ad9ffb68dafb3ae957a1e52e2069dcec76b5adc27284587d614bbb6a8c139')

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
