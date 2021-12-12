# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=pydantic
pkgname=python-$_pkgname
pkgver=1.8.2
pkgrel=3
pkgdesc='Data parsing and validation using Python type hints'
arch=('any')
url='https://github.com/samuelcolvin/pydantic'
license=('MIT')
depends=('python' 'python-typing-extensions')
optdepends=('python-email-validator: email')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner' 'python-pytest-mock')
source=("$pkgname-$pkgver.tar.gz::$url/archive/v$pkgver.tar.gz"
        python310.patch)
sha512sums=('0a28c64b97678b932092e546da877a4a6d104fc7d3b7cb043b3494f0b7c6900cdc1ab8a83bdbd1879956a81da1b28ca27578b1a003bdca3e08f0f107e5690e06'
            '488ffd8a76a0b99a830a1765518da4e67cec42c45db9ca45600fb78f3f5b17542522cdc4aa0f1b74618b7cdebd7410f162cb717bb146478746dfd31a0e2f6991')

prepare() {
  cd $_pkgname-$pkgver
  patch -Np1 -i ../python310.patch
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
