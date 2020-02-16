# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-tqdm
pkgver=4.40.0
pkgrel=1
pkgdesc='Fast, Extensible Progress Meter'
arch=('any')
license=('MIT' 'MPL')
url='https://github.com/tqdm/tqdm'
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-nose' 'python-coverage' 'flake8')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tqdm/tqdm/archive/v$pkgver.tar.gz")
sha512sums=('c4b5cec272a05c04d850cbeb553f9cb195b9a4d5bf6d4110176963e4240ed82541ac3fdaaa64889e2de7979b20e5daef5e5280f7406580f3fd255116bbef8354')

build() {
  cd "$srcdir"/tqdm-$pkgver
  python setup.py build
}

check() {
  cd "$srcdir"/tqdm-$pkgver
  python setup.py egg_info
  PYTHONPATH="$PWD" nosetests --ignore-files="tests_perf\.py"
}

package() {
  cd tqdm-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -D -m644 LICENCE "$pkgdir"/usr/share/licenses/$pkgname/LICENCE
}

# vim:set ts=2 sw=2 et:
