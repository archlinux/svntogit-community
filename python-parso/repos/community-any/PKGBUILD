# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>

_pkgbase=parso
pkgname=python-parso
pkgver=0.7.1
pkgrel=1
pkgdesc="Python parser that supports error recovery and round-trip parsing for different Python versions"
arch=('any')
url="https://github.com/davidhalter/parso"
license=('MIT')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("$pkgname-$pkgver.tar.gz::https://github.com/davidhalter/parso/archive/v$pkgver.tar.gz")
sha512sums=('318969a7a941c4a0948e58643b07b6f5c446ea166b3a8e44a556f0677ec9a36d7dc8c6d37ca7bce3f8276ee3d7144e22fbaaeac90c738fb90f7e94a0cf8abf7d')

check() {
  cd "$_pkgbase-$pkgver"
  pytest test
}

package_python-parso() {
  cd "$_pkgbase-$pkgver"
  python3 setup.py install --root="$pkgdir/" --optimize=1

  install -D -m644 LICENSE.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
