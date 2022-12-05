# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_pkgname=yarl
pkgname=python-yarl
pkgver=1.8.2
pkgrel=1
pkgdesc='Yet another URL library'
url='https://github.com/aio-libs/yarl/'
arch=('x86_64')
license=('Apache')
depends=('glibc' 'python' 'python-multidict' 'python-idna' 'python-typing_extensions')
makedepends=('cython' 'python-setuptools' 'python-build' 'python-installer' 'python-wheel')
checkdepends=('python-pytest' 'python-pytest-runner' 'python-pytest-cov')
source=(https://github.com/aio-libs/yarl/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('d5dcebcec06d520b48a1d879671a92371bd89eabb7be700c129fcc45e763ecc0370cbb5e88c7b9be05ecb3317370231293a8c076ed68d71a36fe953219dd27ea')
b2sums=('1f2cec38bb681f6a59f10253c75e74912d482cdbe0e639e3ba0a43b9d6ab7b7edc1558c9fffaffd7aad9fa905d884e856ff7f7b69dd103800ef62f7f05de90b5')

prepare() {
  cd ${_pkgname}-${pkgver}
  sed 's| .install-cython ||g' -i Makefile
}

build() {
  cd ${_pkgname}-${pkgver}
  make cythonize
  export LANG=en_US.UTF-8
  python -m build --wheel --no-isolation
}

check() {
  cd ${_pkgname}-${pkgver}
  local _python_version=$(python -c 'import sys; print("".join(map(str, sys.version_info[:2])))')
  PYTHONPATH="$PWD/build/lib.linux-$CARCH-cpython-${_python_version}" pytest
}

package() {
  cd ${_pkgname}-${pkgver}
  #LANG=en_US.UTF-8 python setup.py install --root="${pkgdir}" -O1 --skip-build
  export LANG=en_US.UTF-8
  python -m installer --destdir="$pkgdir" dist/*.whl
}

# vim: ts=2 sw=2 et:
