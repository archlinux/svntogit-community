# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-tqdm
pkgver=4.46.1
pkgrel=1
pkgdesc='Fast, Extensible Progress Meter'
arch=('any')
license=('MIT' 'MPL')
url='https://github.com/tqdm/tqdm'
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-nose' 'python-coverage' 'flake8')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tqdm/tqdm/archive/v$pkgver.tar.gz")
sha512sums=('169b04a360b504deccb2782b8ef033f3e0b008df83a56497dfd77739ad48cce284b0983cc8f07a5f8595b875b0d1eb94269b24abacfa334b23b36742f807bc76')

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
