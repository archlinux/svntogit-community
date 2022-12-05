# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: renek <aur@spaceshore.net>

_pkgname=multidict
pkgname=python-${_pkgname}
pkgver=6.0.3
pkgrel=1
pkgdesc='Asyncio-based multidict implementation for Python'
url='https://github.com/aio-libs/multidict'
arch=('x86_64')
license=('APACHE')
depends=('python' 'glibc')
makedepends=('cython' 'python-setuptools' 'git')
checkdepends=('python-pytest' 'python-pytest-cov' 'python-pytest-runner' 'python-psutil' 'python-perf')
source=(https://github.com/aio-libs/multidict/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('95aef45378c0af6ef6b05549d7419ff4ba272430edae37b2fc041a4742d58890ba9475648b8b5ac57d2bff3718519a0201819b274a65ac0b101cf41c8abad812')
b2sums=('b89373a74c6fb4965bc794e7351d6e9563f810ecdb738000ae5573c8b4717f39c4866fd945c9de2afed4f48060ba675d449d7df512c58d5f34b55bc0d8d44ae9')

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
