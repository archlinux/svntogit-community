# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=markdown-it-py
pkgname=python-$_pkgname
pkgver=0.5.6
pkgrel=3
pkgdesc='Python port of markdown-it. Markdown parsing, done right!'
arch=('any')
url='https://github.com/executablebooks/markdown-it-py'
license=('MIT')
depends=('python-attrs')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-pytest-regressions' 'python-pytest-benchmark' 'python-psutil')
source=("$pkgname-$pkgver.tar.gz::$url/archive/v$pkgver.tar.gz")
sha512sums=('0ab604d377c42991b420238688014615213748d079a56b3176d08524a38a54d8346f3f581d8acb11c211fefbb08c210eac76c448a93ffb15171ec355f01c1b39')

build() {
  cd $_pkgname-$pkgver

  python setup.py build
}

check() {
  cd $_pkgname-$pkgver

  pytest
}

package() {
  cd $_pkgname-$pkgver

  python setup.py install --root="$pkgdir" --optimize=1 --skip-build

  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et:
