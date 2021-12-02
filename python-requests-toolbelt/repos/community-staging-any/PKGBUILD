# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: eolianoe <eolianoe At GoogleMAIL DoT com>

pkgname=python-requests-toolbelt
pkgver=0.9.1
pkgrel=7
pkgdesc="A toolbelt of useful classes and functions to be used with python-requests."
arch=('any')
url="https://github.com/requests/toolbelt"
license=('Apache')
depends=('python-requests')
makedepends=('python-setuptools' 'python-requests')
checkdepends=('python-pytest' 'python-betamax' 'python-mock' 'python-pyopenssl')
source=("$pkgname-$pkgver.tar.gz::https://github.com/requests/toolbelt/archive/$pkgver.tar.gz"
        '7188b06330e5260be20bce8cbcf0d5ae44e34eaf.patch::https://github.com/requests/toolbelt/commit/7188b06330e5260be20bce8cbcf0d5ae44e34eaf.patch')
sha512sums=('12667056c225ce0bc88a5959660103feed23810890abd3890ef15581aa64c09c0552c3974473e1742cbe6200bd37d6475ad34ec051e83d4fbf0a33f320dbc0cc'
            '3265c1cc903ee878fecc0a98be935c4471c89c4ed0def6c0862d581b7ca84e97b402dd6e532127d5eca7b04d8f78127116c06324c1bf5199994406cc6c37006e')

prepare() {
  cd "$srcdir"/toolbelt-$pkgver
  patch -p1 <"$srcdir"/7188b06330e5260be20bce8cbcf0d5ae44e34eaf.patch
}

build() {
  cd "$srcdir"/toolbelt-$pkgver
  python setup.py build
}

check() {
  cd "$srcdir"/toolbelt-$pkgver
  py.test -k 'not test_no_content_length_header and not test_read_file and not test_reads_file_from_url_wrapper and not test_x509_der and not test_x509_pem'
}

package() {
  cd toolbelt-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}
