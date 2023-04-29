# Maintainer:
# Contributor: Mantas Mikulėnas <grawity@gmail.com>

_pkgname=requests-gssapi
pkgname=python-requests-gssapi
pkgver=1.2.3
pkgrel=3
pkgdesc="GSSAPI (HTTP Negotiate) authentication for Python-Requests"
url="https://github.com/pythongssapi/requests-gssapi"
arch=(any)
license=(custom:ISC)
depends=(python-gssapi python-requests)
makedepends=(python-setuptools)
source=(https://github.com/pythongssapi/requests-gssapi/archive/v$pkgver/$pkgname-$pkgver.tar.gz)
sha256sums=('0ce61f46476dfd36227d74c330a6e1287236fb5fdb7daa9a54aaa47f0093d815')

build() {
  cd $_pkgname-$pkgver
  python setup.py build
}

package() {
  cd $_pkgname-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
