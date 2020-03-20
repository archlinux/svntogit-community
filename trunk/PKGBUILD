# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=towncrier
pkgver=19.2.0
pkgrel=1
pkgdesc="Utility to produce useful, summarised news files for your project"
arch=('any')
url="https://github.com/hawkowl/towncrier"
license=('MIT')
depends=('python-setuptools' 'python-click' 'python-click-default-group' 'python-incremental'
         'python-jinja' 'python-toml')
checkdepends=('git' 'python-twisted')
source=("$pkgname-$pkgver.tar.gz::https://github.com/hawkowl/towncrier/archive/$pkgver.tar.gz")
sha512sums=('60999446c4ae404fb54ea6282a862621d49f62a2488d31eecf8fed9dd7afa6e01f4feac6e3dd26b882ee75f747424d63d05521e33b5f6b8df7059ce32dbe5c4f')

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
