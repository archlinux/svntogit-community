# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

_name=Nuitka
pkgname=nuitka
pkgver=0.6.13
pkgrel=1
pkgdesc='Python compiler with full language support and CPython compatibility'
arch=('any')
url='https://nuitka.net/'
license=('Apache')
depends=('python-appdirs' 'scons')
makedepends=('python-setuptools')
checkdepends=('ccache' 'fuse2' 'python-boto3' 'python-brotli' 'strace')
optdepends=('ccache: for build caching'
            'chrpath: for building standalone executables')
options=(!emptydirs)
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz")
sha512sums=('93953f8b0c4d915cc13c2791a26b2d14db1cffa8b10ee58527547f1184bcdbc6a0c1082f7ae1a9d0418278561d6118059eb8ab9daee8d3e2a545190a419de361')
b2sums=('81fce164edaa93e221d6f0a3ceced7c045ace3515213a9f74f2d593e6807fbd93ca3b01b6b69ae39d42208f74d478ca14797590d5db9b09cc74c7dedf157e8b0')

prepare() {
  mv -v "${_name}-${pkgver}" "${pkgname}-${pkgver}"
}

build() {
  cd "${pkgname}-${pkgver}"
  python setup.py build
}

check() {
  cd "${pkgname}-${pkgver}"
  # skip tests for other interpreters and those that require network access
  ./tests/run-tests --no-other-python --skip-reflection-test --skip-other-cpython-tests --skip-onefile-tests
}

package() {
  cd "${pkgname}-${pkgver}"
  python setup.py install --skip-build \
                          --optimize=1 \
                          --root="${pkgdir}"
  install -vDm 644 {Changelog,Developer_Manual,README}.rst \
    -t "${pkgdir}/usr/share/doc/${pkgname}/"
}
