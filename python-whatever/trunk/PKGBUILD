# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-whatever
pkgver=0.7
pkgrel=1
pkgdesc='Easy way to make anonymous functions by partial application of operators'
arch=('any')
license=('BSD')
url='https://github.com/Suor/whatever'
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("https://github.com/Suor/whatever/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('b3a5251cfb8e420cded4eb3fd480da66320ca47f7a4cd9c60c76c0bba7698646ab3f19d069397d660ffc67702702fed281adc113accda8ceeff65876d90916b5')

build() {
  cd whatever-$pkgver
  python setup.py build
}

check() {
  cd whatever-$pkgver
  pytest
}

package() {
  cd whatever-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
