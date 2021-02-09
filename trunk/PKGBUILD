# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-tqdm
pkgver=4.56.1
pkgrel=1
pkgdesc='Fast, Extensible Progress Meter'
arch=('any')
license=('MIT' 'MPL')
url='https://github.com/tqdm/tqdm'
depends=('python')
makedepends=('python-setuptools-scm')
checkdepends=('python-pytest' 'python-pytest-asyncio' 'python-pytest-timeout' 'python-numpy'
              'python-pandas' 'python-tensorflow')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tqdm/tqdm/archive/v$pkgver.tar.gz")
sha512sums=('cb7345e28781244402e8c065ff3ad1b93c207ba28a4011528dece59be58066bd0cf40b6770f20f24e2b0ed423f12805f48b0aa4da4ec0db4ca5c6b6f160e40c8')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

build() {
  cd tqdm-$pkgver
  python setup.py build
}

check() {
  cd tqdm-$pkgver
  python setup.py egg_info
  python -m pytest
}

package() {
  cd tqdm-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -D -m644 LICENCE "$pkgdir"/usr/share/licenses/$pkgname/LICENCE
}

# vim:set ts=2 sw=2 et:
