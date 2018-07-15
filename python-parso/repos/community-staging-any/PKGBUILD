# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>

_pkgbase=parso
pkgbase=python-parso
pkgname=('python-parso' 'python2-parso')
pkgver=0.3.1
pkgrel=2
pkgdesc="Python parser that supports error recovery and round-trip parsing for different Python versions"
arch=('any')
url="https://github.com/davidhalter/parso"
license=('MIT')
makedepends=('python' 'python2' 'python-setuptools' 'python2-setuptools')
checkdepends=('python-pytest' 'python2-pytest')
source=("$pkgname-$pkgver.tar.gz::https://github.com/davidhalter/parso/archive/v$pkgver.tar.gz")
md5sums=('55e6d2c26b89c9b9742586eca0e73f32')

check() {
  cd "$_pkgbase-$pkgver"
  pytest test
}

package_python-parso() {
  depends=('python')
  cd "$_pkgbase-$pkgver"
  python3 setup.py install --root="$pkgdir/" --optimize=1

  install -D -m644 LICENSE.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

package_python2-parso() {
  depends=('python2')
  cd "$_pkgbase-$pkgver"
  python2 setup.py install --root="$pkgdir/" --optimize=1

  install -D -m644 LICENSE.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
