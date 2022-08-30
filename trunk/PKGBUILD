# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_pkgname=yarl
pkgname=python-yarl
pkgver=1.8.1
pkgrel=1
pkgdesc='Yet another URL library'
url='https://github.com/aio-libs/yarl/'
arch=('x86_64')
license=('Apache')
depends=('glibc' 'python' 'python-multidict' 'python-idna' 'python-typing_extensions')
makedepends=('cython' 'python-setuptools' 'python-build' 'python-installer' 'python-wheel')
checkdepends=('python-pytest' 'python-pytest-runner' 'python-pytest-cov')
source=(https://github.com/aio-libs/yarl/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('267523216832c2bc83d92a42e621ff519d427e20c1ee84ac657e13f696a2df2259c837486f192d87944f5ebb834beea60ace791eb4c9c632fd7e552eb5dadf1b')
b2sums=('c7390b78abb5074dd29e96848a77fdb31f6224e99d2bcfd5a28a8bd08881f5ff82cf55b2f54c97324d005a0fb3823732a9ed6bd3f1d837e4ac2341b89e2adb30')

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
