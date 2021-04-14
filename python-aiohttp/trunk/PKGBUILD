# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Philipp A. <flying-sheep@web.de>

_pkgname=aiohttp
pkgname=python-aiohttp
_gitcommit=184274d9b28bbfa06ac60e48bf286a761c6a6cb0
pkgver=3.7.4.post0
pkgrel=1
pkgdesc='HTTP client/server for asyncio'
url='https://aiohttp.readthedocs.io'
arch=('x86_64')
license=('Apache')
depends=('python' 'python-chardet' 'python-multidict' 'python-async-timeout'
         'python-yarl' 'python-attrs')
makedepends=('cython' 'python-setuptools' 'git')
checkdepends=('python-pytest' 'python-pytest-runner' 'python-pytest-mock'
              'python-pytest-timeout' 'python-async_generator' 'python-brotli'
              'python-pytest-xdist' 'python-pytest-forked' 'python-pytest-cov'
              'python-trustme' 'python-freezegun' 'gunicorn' 'python-re-assert')
optdepends=('gunicorn: to deploy using Gunicorn'
            'python-aiodns: for fast DNS resolving'
            'python-cchardet: for faster encoding detection'
            'python-brotli: for Brotli transfer-encodings support')
source=(${pkgname}::"git+https://github.com/aio-libs/aiohttp#commit=${_gitcommit}"
        git+https://github.com/nodejs/http-parser
        python-aiohttp-release-resources-pytest.patch
        python-aiohttp-brotli.patch)
sha512sums=('SKIP'
            'SKIP'
            '42db1eb1173f34351a76fcd0be28dbfa1f18be5da4bc0e75adfb4be666e26acc9fbca11a83506f4eee729122110f98512133cdc0a46615f75ee2846645f4fb7a'
            '3bfc6511d0a1a54e20c5b10457041621960da869a752a0b751a424db357d4153578ff1a5e9268f27e4badb2ac01f1c76d23f0058f76b9dd44063f56a046712d8')

pkgver() {
  cd ${pkgname}
  git describe --tags | sed 's/^v//;s/\([^-]*-g\)/r\1/;s/-/./g'
}

prepare() {
  cd ${pkgname}
  git submodule init
  git config submodule."vendor/http-parser".url "${srcdir}/http-parser"
  git submodule update --recursive
  # fix tests
  git revert -n 942c1b801f0ce4b5cd0103be58eb0359edf698a2
  patch -p1 -i ../python-aiohttp-release-resources-pytest.patch
  patch -p1 -i ../python-aiohttp-brotli.patch
  sed 's|.install-cython ||' -i Makefile
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
