# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=towncrier
pkgver=21.3.0
pkgrel=3
pkgdesc="Utility to produce useful, summarised news files for your project"
arch=('any')
url="https://github.com/hawkowl/towncrier"
license=('MIT')
depends=('python-setuptools' 'python-click' 'python-click-default-group' 'python-incremental'
         'python-jinja' 'python-toml')
checkdepends=('git' 'python-twisted')
source=("https://pypi.io/packages/source/t/towncrier/towncrier-$pkgver.tar.gz")
sha512sums=('058a23dfed3a01d831be8034dd5fbdeac08bbaae3e06dfcd83fc4ac18c98ff8ac12d7c4c04e179794d40d305349c89aed0ee8f5fcd173c2793c8c24b35d58df3')

prepare() {
  cd towncrier-$pkgver
  sed -i 's/import mock/from unittest import mock/' src/towncrier/test/test_create.py
}

build() {
  cd towncrier-$pkgver
  python setup.py build
}

check() {
  cd towncrier-$pkgver
  PYTHONPATH="$PWD/build/lib" trial towncrier
}

package() {
  cd towncrier-$pkgver
  python setup.py install -O1 --prefix=/usr --root="$pkgdir"

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}

# vim:set ts=2 sw=2 et:
