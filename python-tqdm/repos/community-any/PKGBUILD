# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-tqdm
pkgver=4.34.0
pkgrel=1
pkgdesc='Fast, Extensible Progress Meter'
arch=('any')
license=('MIT' 'MPL')
url='https://github.com/tqdm/tqdm'
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-nose' 'python-coverage' 'flake8')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tqdm/tqdm/archive/v$pkgver.tar.gz")
sha512sums=('175de13f0fc099b323302166096471eb7f1eab33491261c14b28133ec6b8a555b13a152e5684841197e3cc31eb1c3141bea73d73884129dbb5e9f9b28e841461')

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
