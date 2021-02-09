# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=markdown-it-py
pkgname=python-$_pkgname
pkgver=0.6.2
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
sha512sums=('1a508c89bb51b8902bf916ffe55d341eff6c3df0b29c92bb46e3a9cbc338d4df382e911c7a721fbb2728e1a2279f7c07227ba618d312df4f975e33a4a69c6f0e')

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
