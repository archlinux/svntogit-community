# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: renek <aur@spaceshore.net>

_pkgname=multidict
pkgname=python-${_pkgname}
pkgver=3.2.0
pkgrel=1
pkgdesc='Asyncio-based multidict implementation for Python'
url='https://github.com/aio-libs/multidict'
arch=('i686' 'x86_64')
license=('APACHE')
depends=('python' 'glibc')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest' 'python-psutil')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/multidict/archive/v${pkgver}.tar.gz)
sha256sums=('cefa2da44fea2248c967a2de5ac4cb5a17dfe23a19118c40bf99204b3fb848b7')
sha512sums=('20a127706eaecbaafd19953625aef9dbee4dfddca3a74f5972d6ff0fb3e1a3c0e336a5b305b4b4dd1cf0c447835f362e363445d51c5b311c5db6035a232fad70')

build() {
  cd ${_pkgname}-${pkgver}
  python setup.py build
}

check() {
  cd ${_pkgname}-${pkgver}
  local PYTHONVERSION="$(python -c 'import sys; print("{}.{}".format(sys.version_info.major, sys.version_info.minor))')"
  PYTHONPATH="build/lib.linux-${CARCH}-${PYTHONVERSION}" \
    py.test
}

package() {
  cd ${_pkgname}-${pkgver}
  python setup.py install --root="${pkgdir}" -O1 --skip-build
}

# vim: ts=2 sw=2 et:
