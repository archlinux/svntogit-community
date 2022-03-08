# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: renek <aur@spaceshore.net>

_pkgname=multidict
pkgname=python-${_pkgname}
pkgver=6.0.2
pkgrel=1
pkgdesc='Asyncio-based multidict implementation for Python'
url='https://github.com/aio-libs/multidict'
arch=('x86_64')
license=('APACHE')
depends=('python' 'glibc')
makedepends=('cython' 'python-setuptools' 'git')
checkdepends=('python-pytest' 'python-pytest-cov' 'python-pytest-runner' 'python-psutil' 'python-perf')
source=(https://github.com/aio-libs/multidict/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('508f18c5f731e7438bc7cb84b29aff22422769a8ea4c0ba7c875361d1bb1da78bed2db8b4ca34b833effd03ca3e7f00dabaad64bfce54b3e8d208cdc808083c9')
b2sums=('1fa9b0d92a94ed022849a851f925e132b629216ddd0d5d4772304fd3361a129692f8b49fca2765118ab1cbc306879924d0aa7c6b57b648158a093a9f311a8d30')

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
