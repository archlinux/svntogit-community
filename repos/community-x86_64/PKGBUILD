# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: renek <aur@spaceshore.net>

_pkgname=multidict
pkgname=python-${_pkgname}
pkgver=4.1.0
pkgrel=1
pkgdesc='Asyncio-based multidict implementation for Python'
url='https://github.com/aio-libs/multidict'
arch=('x86_64')
license=('APACHE')
depends=('python' 'glibc')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest' 'python-pytest-cov' 'python-pytest-runner' 'python-psutil' 'python-perf')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/multidict/archive/v${pkgver}.tar.gz)
sha256sums=('40ffcd64b61e5d55f490036e4ab402a13890a49f6a52bbe39113091ac615238e')
sha512sums=('8972ca48146b40fd88f5b0675ed6d45e6887c31fc1d5962203f0fa77a369ef11b0d7739593f5691ae1fd2bbef989940983ddcf0c09acfc5a65b39b6b336571f9')

build() {
  cd ${_pkgname}-${pkgver}
  python setup.py build
}

check() {
  cd ${_pkgname}-${pkgver}
  python setup.py test
}

package() {
  cd ${_pkgname}-${pkgver}
  python setup.py install --root="${pkgdir}" -O1 --skip-build
}

# vim: ts=2 sw=2 et:
