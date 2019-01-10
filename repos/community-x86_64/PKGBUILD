# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Philipp A. <flying-sheep@web.de>

_pkgname=aiohttp
pkgname=python-aiohttp
_gitcommit=8c8375f26a5bbfb8c0f56541aec860b10d99ffc5
pkgver=3.5.2
pkgrel=1
pkgdesc='HTTP client/server for asyncio'
url='https://aiohttp.readthedocs.io'
arch=('x86_64')
license=('Apache')
depends=('python' 'python-chardet' 'python-multidict' 'python-async-timeout'
         'python-yarl' 'python-attrs' 'gunicorn')
makedepends=('cython' 'python-setuptools' 'git')
checkdepends=('python-pytest' 'python-pytest-runner' 'python-pytest-mock'
              'python-pytest-timeout' 'python-async_generator' 'python-brotlipy'
              'python-pytest-xdist' 'python-pytest-forked' 'python-pytest-cov'
              'python-trustme')
source=(${pkgname}::"git+https://github.com/aio-libs/aiohttp#commit=${_gitcommit}"
        git+https://github.com/nodejs/http-parser)
sha512sums=('SKIP'
            'SKIP')

pkgver() {
  cd ${pkgname}
  git describe --always --tags | sed 's/^v//;s/\([^-]*-g\)/r\1/;s/-/./g'
}

prepare() {
  cd ${pkgname}
  git submodule init
  git config submodule."vendor/http-parser".url "${srcdir}/http-parser"
  git submodule update --recursive
}

build() {
  cd ${pkgname}
  python setup.py build
}

check() {
  cd ${pkgname}
  python setup.py test
}

package() {
  cd ${pkgname}
  python setup.py install --root="${pkgdir}" -O1 --skip-build
}

# vim: ts=2 sw=2 et:
