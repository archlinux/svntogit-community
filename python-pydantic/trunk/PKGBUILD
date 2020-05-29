# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=pydantic
pkgname=python-$_pkgname
pkgver=1.5.1
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
sha512sums=('beadba0f57bd669ac97f4d7288cdf9598f6c791f46258ba75a3ec93361ebba010d7b1784e8b50534b12f9fb3606e8cc0cbbc7a9321a1d9a6a29e1e73a057f9c4')

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
}

