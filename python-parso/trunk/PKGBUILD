# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>

_pkgbase=parso
pkgname=python-parso
pkgver=0.8.0
pkgrel=1
pkgdesc="Python parser that supports error recovery and round-trip parsing for different Python versions"
arch=('any')
url="https://github.com/davidhalter/parso"
license=('MIT')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("$pkgname-$pkgver.tar.gz::https://github.com/davidhalter/parso/archive/v$pkgver.tar.gz")
sha512sums=('fe9d1c46cb128d6af9c45f333e49475da795c1ed67572891f4daf08af620814b9db18469be11f771869e0f44acea9446e1419067e1b72affc1cb669a277d6a2c')

check() {
  cd "$_pkgbase-$pkgver"
  pytest test
}

package_python-parso() {
  cd "$_pkgbase-$pkgver"
  python3 setup.py install --root="$pkgdir/" --optimize=1

  install -D -m644 LICENSE.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
