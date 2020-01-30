# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>

_pkgbase=parso
pkgbase=python-parso
pkgname=('python-parso' 'python2-parso')
pkgver=0.6.0
pkgrel=1
pkgdesc="Python parser that supports error recovery and round-trip parsing for different Python versions"
arch=('any')
url="https://github.com/davidhalter/parso"
license=('MIT')
makedepends=('python' 'python2' 'python-setuptools' 'python2-setuptools')
checkdepends=('python-pytest' 'python2-pytest')
source=("$pkgname-$pkgver.tar.gz::https://github.com/davidhalter/parso/archive/v$pkgver.tar.gz")
sha512sums=('1382b5005ea7e19c3d4f8910b47e9b730e61045fdb16d833a43a7eded8bd568a7528f1822bf193d3c110a5496f53a540ca5028dd10bfd4a59193d58a7e457014')

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
