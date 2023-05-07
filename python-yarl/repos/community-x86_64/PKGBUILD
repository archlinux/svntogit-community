# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_pkgname=yarl
pkgname=python-yarl
pkgver=1.9.2
pkgrel=1
pkgdesc='Yet another URL library'
url='https://github.com/aio-libs/yarl/'
arch=('x86_64')
license=('Apache')
depends=('glibc' 'python' 'python-multidict' 'python-idna')
makedepends=('cython' 'python-setuptools' 'python-build' 'python-installer' 'python-wheel')
checkdepends=('python-pytest' 'python-pytest-runner' 'python-pytest-cov')
source=(https://github.com/aio-libs/yarl/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('c6159ed26f946533543f4238feb90986422dda3bd6c2c68e274d2745efb4eccad76dfbc129370d8c5e24584fc459dbc0002fd66fbdad9291a30041c929dee6d8')
b2sums=('ee8952b3cb252e18a2e04fbea96001b11ed39c72b0168adb0c961a1626842d0de480bde7de7423d5408fc095d66d6b3f829983da78e7d0c5925593afb1dd0fb8')

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
