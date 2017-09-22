# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>

_pkgbase=parso
pkgbase=python-parso
pkgname=('python-parso' 'python2-parso')
pkgver=0.1.0
pkgrel=1
pkgdesc="Python parser that supports error recovery and round-trip parsing for different Python versions"
arch=('any')
url="https://github.com/davidhalter/parso"
license=('MIT')
makedepends=('python' 'python2')
checkdepends=('python-pytest' 'python2-pytest')
source=("$pkgname-$pkgver.tar.gz::https://github.com/davidhalter/parso/archive/v$pkgver.tar.gz")
md5sums=('12c9648d902aafc69f9141e4c500dc12')

check() {
  cd "$_pkgbase-$pkgver"
  pytest test
}

package_python-parso() {
  depends=('python')
  cd "$_pkgbase-$pkgver"
  python3 setup.py install --root="$pkgdir/" --optimize=1
}

package_python2-parso() {
  depends=('python2')
  cd "$_pkgbase-$pkgver"
  python2 setup.py install --root="$pkgdir/" --optimize=1
}
