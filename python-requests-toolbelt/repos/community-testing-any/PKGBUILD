# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: eolianoe <eolianoe At GoogleMAIL DoT com>

pkgname=python-requests-toolbelt
pkgver=0.9.1
pkgrel=5
pkgdesc="A toolbelt of useful classes and functions to be used with python-requests."
arch=('any')
url="https://github.com/requests/toolbelt"
license=('Apache')
depends=('python-requests')
makedepends=('python-setuptools' 'python-requests')
checkdepends=('python-pytest' 'python-betamax' 'python-mock' 'python-pyopenssl')
source=("$pkgname-$pkgver.tar.gz::https://github.com/requests/toolbelt/archive/$pkgver.tar.gz")
sha512sums=('12667056c225ce0bc88a5959660103feed23810890abd3890ef15581aa64c09c0552c3974473e1742cbe6200bd37d6475ad34ec051e83d4fbf0a33f320dbc0cc')

build() {
  cd "$srcdir"/toolbelt-$pkgver
  python setup.py build
}

check() {
  cd "$srcdir"/toolbelt-$pkgver
  py.test -k 'not test_no_content_length_header and not test_read_file and not test_reads_file_from_url_wrapper'
}

package() {
  cd toolbelt-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}
