# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-tqdm
pkgver=4.55.2
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
sha512sums=('20bb4b1c45362417f3b1d3a8eef2de1fc3efc6cbf74d4958c68981b44236a5a41d62819e60076c5c90dcce4da9129c5479c85d00e1b5ec45081a860fbcae9d71')

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
