# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=pydantic
pkgname=python-$_pkgname
pkgver=1.7.2
pkgrel=3
pkgdesc='Data parsing and validation using Python type hints'
arch=('any')
url='https://github.com/samuelcolvin/pydantic'
license=('MIT')
depends=('python')
optdepends=('python-email-validator: email'
            'python-typing-extensions: typing_extensions')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner' 'python-pytest-mock')
source=("$pkgname-$pkgver.tar.gz::$url/archive/v$pkgver.tar.gz")
sha512sums=('59398b2f3e842180be7f9fca8156b1a983c9668df30ea82663a8abc09775950ba69e5ddf20dd8a899a12ee96b2f3a8dc5ff12da543673281620bdef47894c976')

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
