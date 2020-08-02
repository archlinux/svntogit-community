# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_pkgname=yarl
pkgname=python-yarl
pkgver=1.5.1
pkgrel=1
pkgdesc='Yet another URL library'
url='https://github.com/aio-libs/yarl/'
arch=('x86_64')
license=('Apache')
depends=('glibc' 'python' 'python-multidict' 'python-idna' 'python-typing_extensions')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest' 'python-pytest-runner')
source=(https://github.com/aio-libs/yarl/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('ab1c106533c54d5c6a4ec0a88b36ddb73ee6a009ae2728986f80ff55ab475db241b8b7e4a7c8419bf58dbd79ebbcc41a6ad9173b10310d02ca6e428d579e064b')
b2sums=('40e04a313fd126a6b1ea16df976b93e6c6a21bc23ea199900d8e8ff0066fa8baceed4ef0c089492974c34b3225e9ce3b660d7d338fa1dd80e7088e060c04f2da')

prepare() {
  cd ${_pkgname}-${pkgver}
  sed 's| .install-cython ||g' -i Makefile
}

build() {
  cd ${_pkgname}-${pkgver}
  make cythonize
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
