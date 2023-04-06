# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-jsonlines
pkgver=3.1.0
pkgrel=2
pkgdesc="Library with helpers for the jsonlines file format"
url="https://github.com/wbolster/jsonlines"
license=('BSD')
arch=('any')
depends=('python-attrs')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("https://github.com/wbolster/jsonlines/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('f5fd35bbdc94106afbf8f837bcc3440348772f3b6011b2fb8d7cf86a8ec881c5350aebcd3ae85d45ec88b8deddc68c8e417eaf172f7777c009e42beb7f64ff61')

build() {
  cd jsonlines-$pkgver
  python setup.py build
}

check() {
  cd jsonlines-$pkgver
  python -m pytest
}

package() {
  cd jsonlines-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE.rst -t "$pkgdir"/usr/share/licenses/$pkgname/
}
