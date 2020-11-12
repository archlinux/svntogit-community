# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-whatever
pkgver=0.6
pkgrel=3
pkgdesc='Easy way to make anonymous functions by partial application of operators'
arch=('any')
license=('BSD')
url='https://github.com/Suor/whatever'
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner')
source=("$pkgname-$pkgver.tar.gz::https://github.com/Suor/whatever/archive/$pkgver.tar.gz")
sha512sums=('f982100f0d6a8bf4c30e452a083c75f4cb2bca07e57e40ba4fd66baca752f039aea9519ffb97b3d43708df0ff5e981d0c4d03773f225106aa2f43e7770ee1975')

build() {
  cd whatever-$pkgver
  python setup.py build
}

check() {
  cd whatever-$pkgver
  python setup.py pytest
}

package() {
  cd whatever-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -D -m644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
