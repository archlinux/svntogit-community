# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: renek <aur@spaceshore.net>

_pkgname=multidict
pkgname=python-${_pkgname}
pkgver=6.0.4
pkgrel=2
pkgdesc='Asyncio-based multidict implementation for Python'
url='https://github.com/aio-libs/multidict'
arch=('x86_64')
license=('APACHE')
depends=('python' 'glibc')
makedepends=('cython' 'python-setuptools' 'git')
checkdepends=('python-pytest' 'python-pytest-cov' 'python-pytest-runner' 'python-psutil' 'python-perf')
source=(https://github.com/aio-libs/multidict/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('6f9e6ff16a104d40b0cb59860af9cb1a98e8d3a256626f77600c4895e6ef692b31880273f204e7ecdeb574407dd7c2e4326ad7cd9c08b1095011d6ba3793b86e')
b2sums=('2cf25ac2af57289432dfc6617f35a9f1310469b8d7b6a762e63f4f08b3cb8235c7115c4072fc2ffeec417b49af8a97654c7d69e8e20507fd553fab074e42b1cf')

build() {
  cd ${_pkgname}-${pkgver}
  python setup.py build
}

check() {
  cd ${_pkgname}-${pkgver}
  pytest
}

package() {
  cd ${_pkgname}-${pkgver}
  python setup.py install --root="${pkgdir}" -O1 --skip-build
}

# vim: ts=2 sw=2 et:
