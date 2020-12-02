# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=towncrier
pkgver=19.9.0rc1
pkgrel=3
pkgdesc="Utility to produce useful, summarised news files for your project"
arch=('any')
url="https://github.com/hawkowl/towncrier"
license=('MIT')
depends=('python-setuptools' 'python-click' 'python-click-default-group' 'python-incremental'
         'python-jinja' 'python-toml')
checkdepends=('git' 'python-twisted')
source=("https://pypi.io/packages/source/t/towncrier/towncrier-$pkgver.tar.gz")
sha512sums=('b0654da9f90356522d8ddb029c7564be469be64bfb4684e97cae9f44e028795f54c15a8a59d5bdb2710580b5a9649fd53a500b5eadeec846108d079a3318c241')

build() {
  cd towncrier-$pkgver
  python setup.py build
}

check() {
  cd towncrier-$pkgver
  PYTHONPATH="$PWD/build/lib" trial3 towncrier
}

package() {
  cd towncrier-$pkgver
  python setup.py install -O1 --prefix=/usr --root="$pkgdir"

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}

# vim:set ts=2 sw=2 et:
