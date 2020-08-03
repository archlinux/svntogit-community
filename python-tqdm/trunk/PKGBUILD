# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-tqdm
pkgver=4.48.1
pkgrel=1
pkgdesc='Fast, Extensible Progress Meter'
arch=('any')
license=('MIT' 'MPL')
url='https://github.com/tqdm/tqdm'
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-nose' 'python-coverage' 'flake8')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tqdm/tqdm/archive/v$pkgver.tar.gz")
sha512sums=('3b23c1908974e4f136d176b7f0d53ef8f1b5f85f5828321492aa9aa768b677148094f4457ddd6896a5dec7463fd117142b6ceeae7b950afd5bf09d7423fda024')

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
