# Maintainer: Felix Yan <felixonmars@archlinux.org>

_pkgname=tqdm
pkgname=python-$_pkgname
pkgver=4.63.2
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
sha512sums=('a8e721421fbf3782aead9ad05237a5fb9a0f7b379fed808549852016153af9af41830a7cf7cdb9a148eb449ab3d770fa9899912f16f8f88b4cc793ac9f9af9b8')

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
