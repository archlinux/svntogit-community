# Maintainer: Felix Yan <felixonmars@archlinux.org>

_pkgname=tqdm
pkgname=python-$_pkgname
pkgver=4.61.0
pkgrel=1
pkgdesc='Fast, Extensible Progress Meter'
arch=('any')
license=('MIT' 'MPL')
url='https://github.com/tqdm/tqdm'
depends=('python')
optdepends=('python-requests: telegram')
makedepends=('python-setuptools-scm' 'python-toml')
checkdepends=('python-pytest' 'python-pytest-asyncio' 'python-pytest-timeout' 'python-numpy'
              'python-pandas' 'python-tensorflow' 'python-rich' 'python-dask' 'tk')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tqdm/tqdm/archive/v$pkgver.tar.gz")
sha512sums=('27e439b9e03dfa4fba9d194a254efdffc625940f7182048da869f47f67d3223cb42ff1c91426c082caf50677c405469b75e510e3f8e9650cb2a5a512d4523888')

build() {
  cd $_pkgname-$pkgver

  export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

  python setup.py build
}

check() {
  cd $_pkgname-$pkgver

  export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

  python -m venv --system-site-packages test-env

  test-env/bin/python setup.py install
  test-env/bin/python -m pytest -k 'not test_dask'
}

package() {
  cd $_pkgname-$pkgver

  export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

  python setup.py install --root="$pkgdir" --optimize=1

  install -D -m644 LICENCE "$pkgdir"/usr/share/licenses/$pkgname/LICENCE
}

# vim:set ts=2 sw=2 et:
