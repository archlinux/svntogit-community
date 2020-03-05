# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-jeepney
pkgver=0.4.3
pkgrel=1
pkgdesc="Low-level, pure Python DBus protocol wrapper"
url="https://gitlab.com/takluyver/jeepney"
license=('MIT')
arch=('any')
depends=('python')
source=("https://pypi.io/packages/source/j/jeepney/jeepney-$pkgver.tar.gz")
sha512sums=('bfb12c9259a57324759f8be44d1faf2c0535762e72db5f1370e64cb144c0fc537c9bc9cfb9b075932fb3a20e3ef4e0c990c10905cc5a69e3fb088e8de4193689')

build() {
  cd jeepney-$pkgver
  python setup.py build
}

package() {
  cd jeepney-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
