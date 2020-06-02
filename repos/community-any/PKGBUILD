# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-nodeenv
pkgver=1.4.0
pkgrel=1
pkgdesc="Node.js virtual environment builder"
url="https://github.com/ekalinin/nodeenv"
license=('BSD')
arch=('any')
depends=('python' 'make')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner' 'python-coverage' 'python-mock')
source=("$pkgname-$pkgver.tar.gz::https://github.com/ekalinin/nodeenv/archive/$pkgver.tar.gz")
sha512sums=('0c4faa562ca00a1a4196f9eace87d32a7d5d9ea39c9272a886eeb2ce3538bf071041efb1f32fb7511793e6f5d12ecca1d7d8e6b8639b10a2feed35a2eb2712a6')

build() {
  cd nodeenv-$pkgver
  python setup.py build
}

check() {
  cd nodeenv-$pkgver
  python setup.py pytest
}

package() {
  cd nodeenv-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
