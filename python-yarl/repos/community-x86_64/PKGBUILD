# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_pkgname=yarl
pkgname=python-yarl
pkgver=1.2.5
pkgrel=1
pkgdesc='Yet another URL library'
url='https://github.com/aio-libs/yarl/'
arch=('x86_64')
license=('Apache')
depends=('glibc' 'python' 'python-multidict' 'python-idna')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest' 'python-pytest-runner')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/yarl/archive/v${pkgver}.tar.gz)
sha256sums=('dd5d9c9ec94eb6b2467de42e7fe6725c8508070d774a13aa2f0695f0945cec19')
sha512sums=('dcc9b7317ea74a382f2fa6132e4928728f229255a4625fdea47682337ee1ae91a4a9ea2841563f6a04e67a25acb412abbc6ca2ddf4825397d5c9181886d125f2')

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
