# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Maintainer: Jonas Witschel <diabonas@archlinux.org>
# Contributor: Philipp A. <flying-sheep@web.de>

_pkgname=aiohttp
pkgname=python-aiohttp
_gitcommit=30b7a4e99677b4014dda2372504343bb05fc983e
pkgver=3.8.3
pkgrel=6
pkgdesc='HTTP client/server for asyncio'
url='https://aiohttp.readthedocs.io'
arch=('x86_64')
license=('Apache')
depends=('python' 'python-chardet' 'python-multidict' 'python-async-timeout'
         'python-yarl' 'python-attrs' 'python-charset-normalizer'
         'python-aiosignal' 'python-frozenlist')
makedepends=('git' 'cython' 'npm' 'python-build' 'python-installer'
             'python-setuptools' 'python-wheel')
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
  git -c protocol.file.allow=always submodule update --recursive
  sed 's|.install-cython ||' -i Makefile

  # This test calls the Python interpreter, we need to make sure that the path
  # for the C extensions is correct there as well
  sed -i "s/import {import_path!s}/import sys; sys.path.insert(0, '{os.environ['PYTHONPATH']}'); &/" \
      tests/test_circular_imports.py

  sed -e 's|charset-normalizer >=2.0, < 3.0|charset-normalizer >=2.0, < 4.0|' -i setup.cfg
}

build() {
  cd ${pkgname}
  make generate-llhttp cythonize
  python -m build --wheel --no-isolation
}

check() {
  cd ${pkgname}
  local _python_version=$(python -c 'import sys; print("".join(map(str, sys.version_info[:2])))')
  PYTHONPATH="$PWD/build/lib.linux-$CARCH-cpython-${_python_version}" pytest -k 'not test_default_loop[pyloop] and not test_ctor_global_loop and not test_set_loop_default_loop'
}

package() {
  cd ${pkgname}
  python -m installer --destdir="$pkgdir" dist/*.whl
}

# vim: ts=2 sw=2 et:
