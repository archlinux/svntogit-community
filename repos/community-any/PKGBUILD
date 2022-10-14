# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: eolianoe <eolianoe At GoogleMAIL DoT com>

pkgname=python-requests-toolbelt
pkgver=0.10.0
pkgrel=1
pkgdesc="A toolbelt of useful classes and functions to be used with python-requests."
arch=('any')
url="https://github.com/requests/toolbelt"
license=('Apache')
depends=('python-requests')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-betamax' 'python-ndg-httpsclient' 'python-pyopenssl')
source=("$pkgname-$pkgver.tar.gz::https://github.com/requests/toolbelt/archive/$pkgver.tar.gz")
sha512sums=('f5c16881ad7abf4fa6df76208ed1916856acbf2d86634384198511527912ef739048588eef9a629da24c80124c904b51b1bbb5fa03329bf353e3522b222dab58')

build() {
  cd toolbelt-$pkgver
  python setup.py build
}

check() {
  cd toolbelt-$pkgver
  pytest --deselect tests/test_multipart_encoder.py::TestFileFromURLWrapper::test_no_content_length_header \
         --deselect tests/test_multipart_encoder.py::TestFileFromURLWrapper::test_read_file \
         --deselect tests/test_multipart_encoder.py::TestMultipartEncoder::test_reads_file_from_url_wrapper \
         --deselect tests/test_x509_adapter.py::TestX509Adapter::test_x509_der \
         --deselect tests/test_x509_adapter.py::TestX509Adapter::test_x509_pem
}

package() {
  cd toolbelt-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}
