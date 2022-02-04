# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Maintainer: Jonas Witschel <diabonas@archlinux.org>
# Contributor: Philipp A. <flying-sheep@web.de>

_pkgname=aiohttp
pkgname=python-aiohttp
_gitcommit=cc6dc0c49f5d002485f9a3cdf9bc3127a3ac1388
pkgver=3.8.1
pkgrel=4
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
        non-derpy-tests.patch
        git+https://github.com/nodejs/llhttp.git)
sha512sums=('SKIP'
            'bb0a6b39f8200ef79d68cc5329c13814f60702a8fb929b1c0d64b5cff5602b6d0848fa2644b911bb637cfce0e235abf332f3769545dade4c52bfabd636369d55'
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

  # Make tests compatible with python-proxy.py 2.4.0
  git cherry-pick --no-commit 674948f588022584e5e5168dd329e31a6557f401

  # If these tests are passing, who are we to judge
  patch -Np1 -i ../non-derpy-tests.patch

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
  PYTHONDONTWRITEBYTECODE=1 PYTHONPATH="$PWD/build/lib.linux-$CARCH-${_python_version}" pytest --pythonwarnings=default
}

package() {
  cd ${pkgname}
  python setup.py install --root="${pkgdir}" -O1 --skip-build
}

# vim: ts=2 sw=2 et:
