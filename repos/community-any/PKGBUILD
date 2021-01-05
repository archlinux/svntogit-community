# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=markdown-it-py
pkgname=python-$_pkgname
pkgver=0.6.1
pkgrel=1
pkgdesc='Python port of markdown-it. Markdown parsing, done right!'
arch=('any')
url='https://github.com/executablebooks/markdown-it-py'
license=('MIT')
depends=('python-attrs')
optdepends=('python-mdit_py_plugins: core plugins')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-pytest-regressions' 'python-pytest-benchmark' 'python-psutil' 'python-mdit_py_plugins')
source=("$pkgname-$pkgver.tar.gz::$url/archive/v$pkgver.tar.gz")
sha512sums=('10d13470a20b00e18daefb8ef0fcd5aea7bbcfef88d69670553f8e2f72528467a6f0121824896b4329f38b8979dbb7152452da7f1bfb87d9579c2075754635bd')

build() {
  cd $_pkgname-$pkgver

  python setup.py build
}

check() {
  cd $_pkgname-$pkgver

  pytest -k 'not test_linkify'
}

package() {
  cd $_pkgname-$pkgver

  python setup.py install --root="$pkgdir" --optimize=1 --skip-build

  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et:
