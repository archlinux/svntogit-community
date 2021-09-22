# Maintainer: Felix Yan <felixonmars@archlinux.org>

_pkgname=tqdm
pkgname=python-$_pkgname
pkgver=4.62.3
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
sha512sums=('4ee74d89697b726382a50a51c4ed6001014105068dd909e6809b4db408af570e3af3d046cff476017cd5107b26459a0b0e18a80c87b883d5d6a0af23c8d0f8c2')

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
