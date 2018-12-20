# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_pkgname=yarl
pkgname=python-yarl
pkgver=1.3.0
pkgrel=1
pkgdesc='Yet another URL library'
url='https://github.com/aio-libs/yarl/'
arch=('x86_64')
license=('Apache')
depends=('glibc' 'python' 'python-multidict' 'python-idna')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest' 'python-pytest-runner')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/yarl/archive/v${pkgver}.tar.gz)
sha256sums=('0d4acfd6c750612871e11c49eea43213949f1528686a184eefc1366142a6fbb3')
sha512sums=('36c55ac73830629045399e409f9e097d2e231e64f457c095003a2dd0e48899145e5e970a397458c8b1b1fbd8c24885774cf6bd7ea0b9bf67cd192c46be90af83')

build() {
  cd ${_pkgname}-${pkgver}
  LANG=en_US.UTF-8 python setup.py build
}

check() {
  cd ${_pkgname}-${pkgver}
  python setup.py test
}

package() {
  cd ${_pkgname}-${pkgver}
  LANG=en_US.UTF-8 python setup.py install --root="${pkgdir}" -O1 --skip-build
}

# vim: ts=2 sw=2 et:
