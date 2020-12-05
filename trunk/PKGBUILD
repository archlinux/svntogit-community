# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-tqdm
pkgver=4.54.1
pkgrel=1
pkgdesc='Fast, Extensible Progress Meter'
arch=('any')
license=('MIT' 'MPL')
url='https://github.com/tqdm/tqdm'
depends=('python')
makedepends=('python-setuptools-scm')
checkdepends=('python-pytest' 'python-pytest-asyncio' 'python-numpy' 'python-pandas'
              'python-tensorflow')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tqdm/tqdm/archive/v$pkgver.tar.gz")
sha512sums=('e08d50497396e7a45c878afff4cb264c36adc5540595db45ec39ea691a3dfe5106958eba57582cd82207c2563a1e23f3c6b332d4e84b95dcec8cf03dc27bfc90')

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
