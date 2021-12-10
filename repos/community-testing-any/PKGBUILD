# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-nodeenv
pkgver=1.6.0
pkgrel=3
pkgdesc="Node.js virtual environment builder"
url="https://github.com/ekalinin/nodeenv"
license=('BSD')
arch=('any')
depends=('python' 'make')
optdepends=('nodejs: for --node=system')
makedepends=('python-setuptools')
checkdepends=('nodejs' 'python-pytest-runner' 'python-coverage' 'python-mock')
source=("$pkgname-$pkgver.tar.gz::https://github.com/ekalinin/nodeenv/archive/$pkgver.tar.gz")
sha512sums=('abf4fe55ba478570a32ff3bb24fc3c60ba2d100822f8295c4c55c301ccdff2dc2d20ef76990ea3ac203e30db8a1e85f3ef2df671f87c0cf7305cf1aeb788efdd')

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
