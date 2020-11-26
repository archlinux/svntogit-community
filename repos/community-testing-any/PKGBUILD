# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-nodeenv
pkgver=1.5.0
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
sha512sums=('645911f6ab173bf0e7b68fca9741f1deeb2d486dea99f43d542f86b2ac34439e03da18a6e4de49e3dd45fb89b3c87005b184ca4b73aa0549e75a86191e045e02')

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
