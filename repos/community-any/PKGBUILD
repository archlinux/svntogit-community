# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=pydantic
pkgname=python-$_pkgname
pkgver=1.6.1
pkgrel=1
pkgdesc='Data parsing and validation using Python type hints'
arch=('any')
url='https://github.com/samuelcolvin/pydantic'
license=('MIT')
depends=('python')
optdepends=('python-email-validator: email'
            'python-typing-extensions: typing_extensions')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner')
source=("$pkgname-$pkgver.tar.gz::$url/archive/v$pkgver.tar.gz")
sha512sums=('b0442f78a661f56d29697da7e27393261420bdb0f08473d2f7872145a49a18de8c17c903d0899a44263bcd8229e8790161da032dd5a3d5f2dae347c66bd6a567')

prepare() {
  rm $_pkgname-$pkgver/tests/test_validators.py
}

build() {
  cd $_pkgname-$pkgver

  python setup.py build
}

check() {
  cd $_pkgname-$pkgver

  python setup.py pytest
}

package() {
  cd $_pkgname-$pkgver

  python setup.py install --root="$pkgdir" --optimize=1 --skip-build

  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

