# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-tqdm
pkgver=4.64.1
_commit=6791e8c5b3d6c30bdd2060c346996bfb5a6f10d1
pkgrel=2
pkgdesc='Fast, Extensible Progress Meter'
arch=('any')
license=('MIT' 'MPL')
url='https://github.com/tqdm/tqdm'
depends=('python')
optdepends=('python-requests: telegram')
makedepends=('git' 'python-setuptools-scm' 'python-toml')
checkdepends=('python-pytest' 'python-pytest-asyncio' 'python-pytest-timeout' 'python-numpy'
              'python-pandas' 'python-rich' 'python-dask' 'tk')
source=("git+https://github.com/tqdm/tqdm.git#commit=$_commit")
sha512sums=('SKIP')

build() {
  cd tqdm
  python setup.py build
}

check() {
  cd tqdm
  python -m venv --system-site-packages test-env
  test-env/bin/python setup.py install
  test-env/bin/python -m pytest -k 'not test_dask'
}

package() {
  cd tqdm
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENCE -t "$pkgdir"/usr/share/licenses/$pkgname/
}

# vim:set ts=2 sw=2 et:
