# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>

_pkgbase=parso
pkgname=python-parso
pkgver=0.7.0
pkgrel=1
pkgdesc="Python parser that supports error recovery and round-trip parsing for different Python versions"
arch=('any')
url="https://github.com/davidhalter/parso"
license=('MIT')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("$pkgname-$pkgver.tar.gz::https://github.com/davidhalter/parso/archive/v$pkgver.tar.gz")
sha512sums=('41ad60b1d7dff682281059aabff0d43ccd3048b6cc6ee3e9e141d4a0a965fd99449f6d3f23689914c1f7bda371e3cc86266775a1c23fb1c430ea689c916fbb71')

check() {
  cd "$_pkgbase-$pkgver"
  pytest test
}

package_python-parso() {
  cd "$_pkgbase-$pkgver"
  python3 setup.py install --root="$pkgdir/" --optimize=1

  install -D -m644 LICENSE.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
