# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=towncrier
pkgver=21.9.0
pkgrel=1
pkgdesc="Utility to produce useful, summarised news files for your project"
arch=('any')
url="https://github.com/hawkowl/towncrier"
license=('MIT')
depends=('python-setuptools' 'python-click' 'python-click-default-group' 'python-incremental'
         'python-jinja' 'python-tomli')
checkdepends=('git' 'python-twisted')
source=("https://pypi.io/packages/source/t/towncrier/towncrier-$pkgver.tar.gz")
sha512sums=('9a54eca115b1d1810de6ea383eaec3a40ae27fc50c1c9fdd19e45b6dd6d355286f8baa1085c876976623121580488d9507279b80c951e5bff327443c6f12d6d4')

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
  python setup.py install --root="$PWD/tmp_install" --optimize=1
  PYTHONPATH="$PWD/tmp_install/usr/lib/python3.10/site-packages" PATH="$PWD/tmp_install/usr/bin:$PATH" trial towncrier
}

package() {
  cd towncrier-$pkgver
  python setup.py install -O1 --prefix=/usr --root="$pkgdir"

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}

# vim:set ts=2 sw=2 et:
