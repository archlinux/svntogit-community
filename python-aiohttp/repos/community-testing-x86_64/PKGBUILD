# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Philipp A. <flying-sheep@web.de>

_pkgname=aiohttp
pkgname=python-aiohttp
_gitcommit=208a4eb6dbf5373d9f5a9f18efac839a6448eadc
pkgver=3.8.0
pkgrel=1
pkgdesc='HTTP client/server for asyncio'
url='https://aiohttp.readthedocs.io'
arch=('x86_64')
license=('Apache')
depends=('python' 'python-chardet' 'python-multidict' 'python-async-timeout'
         'python-yarl' 'python-attrs' 'python-charset-normalizer'
         'python-aiosignal' 'python-frozenlist')
makedepends=('cython' 'python-setuptools' 'git' 'npm')
checkdepends=('python-pytest' 'python-pytest-runner' 'python-pytest-mock'
              'python-pytest-timeout' 'python-async_generator' 'python-brotli'
              'python-pytest-xdist' 'python-pytest-forked' 'python-pytest-cov'
              'python-trustme' 'python-freezegun' 'gunicorn' 'python-re-assert'
              'python-proxy.py')
optdepends=('gunicorn: to deploy using Gunicorn'
            'python-aiodns: for fast DNS resolving'
            'python-cchardet: for faster encoding detection'
            'python-brotli: for Brotli transfer-encodings support')
source=(${pkgname}::"git+https://github.com/aio-libs/aiohttp#commit=${_gitcommit}"
        git+https://github.com/nodejs/llhttp.git)
sha512sums=('SKIP'
            'SKIP')

pkgver() {
  cd ${pkgname}
  git describe --tags | sed 's/^v//;s/\([^-]*-g\)/r\1/;s/-/./g'
}

prepare() {
  cd ${pkgname}
  git submodule init
  git config submodule."vendor/llhttp".url "${srcdir}/llhttp"
  git submodule update --recursive
  sed 's|.install-cython ||' -i Makefile

  # This test fails with the error "coroutine 'BaseTestServer.close' was never
  # awaited", which does not appear to be a packaging issue
  sed -i '/test_aiohttp_request_coroutine/i @pytest.mark.xfail' tests/test_client_functional.py
}

build() {
  cd ${pkgname}
  make generate-llhttp cythonize
  python setup.py build
}

check() {
  cd ${pkgname}
  local _python_version=$(python -c 'import sys; print(".".join(map(str, sys.version_info[:2])))')

  # Without --pythonwarnings=default, the test suite does not even start due to
  # an unrelated DeprecationWarning from python-packaging
  PYTHONPATH="$PWD/build/lib.linux-$CARCH-${_python_version}" pytest --pythonwarnings=default
}

package() {
  cd ${pkgname}
  python setup.py install --root="${pkgdir}" -O1 --skip-build
}

# vim: ts=2 sw=2 et:
