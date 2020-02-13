# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-tqdm
pkgver=4.35.0
pkgrel=1
pkgdesc='Fast, Extensible Progress Meter'
arch=('any')
license=('MIT' 'MPL')
url='https://github.com/tqdm/tqdm'
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-nose' 'python-coverage' 'flake8')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tqdm/tqdm/archive/v$pkgver.tar.gz")
sha512sums=('f4e7fe8f76480e7918e0e723d818ae5bb97a540389302a74f7139b0d5a4cd31a7514d2b8bf7f8efa1cf7c313d5dcfe250505ac15118bae863aa50ec1a4517de4')

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
