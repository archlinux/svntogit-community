# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>

_pkgbase=parso
pkgbase=python-parso
pkgname=('python-parso' 'python2-parso')
pkgver=0.6.1
pkgrel=1
pkgdesc="Python parser that supports error recovery and round-trip parsing for different Python versions"
arch=('any')
url="https://github.com/davidhalter/parso"
license=('MIT')
makedepends=('python' 'python2' 'python-setuptools' 'python2-setuptools')
checkdepends=('python-pytest' 'python2-pytest')
source=("$pkgname-$pkgver.tar.gz::https://github.com/davidhalter/parso/archive/v$pkgver.tar.gz")
sha512sums=('98cc20a3378c89b870df5e5df52f2c2091c1a133ea9701141ed90edbb05c5b8ddf30dcc19069cc19666f34e37f8ca64e37bfd701314adb24b0a10ab197862cf1')

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
