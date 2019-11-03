# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Philipp A. <flying-sheep@web.de>

_pkgname=aiohttp
pkgname=python-aiohttp
_gitcommit=6a5ab96bd9cb404b4abfd5160fe8f34a29d941e5
pkgver=3.6.2
pkgrel=2
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
              'python-trustme' 'python-freezegun')
source=(${pkgname}::"git+https://github.com/aio-libs/aiohttp#commit=${_gitcommit}"
        git+https://github.com/nodejs/http-parser
        aiohttp-python-3.8.patch)
sha512sums=('SKIP'
            'SKIP'
            '2a8e2851d23c848ae3bc53cee4b296decf195ac854dffd8685fd43801870fb4854936b273a16e72d582ef055a16c1d580d4feda51f905c981e09364dbee5c2d9')

pkgver() {
  cd ${pkgname}
  git describe --tags | sed 's/^v//;s/\([^-]*-g\)/r\1/;s/-/./g'
}

prepare() {
  cd ${pkgname}
  git submodule init
  git config submodule."vendor/http-parser".url "${srcdir}/http-parser"
  git submodule update --recursive
  sed 's|.install-cython ||' -i Makefile

  patch -p1 -i ../aiohttp-python-3.8.patch # Fix warnings with python 3.8
}

build() {
  cd ${pkgname}
  make cythonize
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
