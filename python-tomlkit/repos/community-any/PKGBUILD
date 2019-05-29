# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-tomlkit
pkgver=0.5.3
_tomltestcommit=f910e151d1b14d94b1e8a4264db0814fb03520d9
pkgrel=3
pkgdesc="Style-preserving TOML library for Python"
url="https://github.com/sdispater/tomlkit"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('python-dephell')
checkdepends=('python-pytest')
source=("$pkgname-$pkgver.tar.gz::https://github.com/sdispater/tomlkit/archive/$pkgver.tar.gz"
        "toml-test-$_tomltestcommit.tar.gz::https://github.com/BurntSushi/toml-test/archive/$_tomltestcommit.tar.gz")
sha512sums=('68f2c2df5bfe0986a8530bb72d35179be974105a11427a59d8d88ea2c1828284ed5518e9fdd90f82ab508e44e63176f7efb78acccc8f4baaa901805979f32c90'
            '49431bf72cd5b40b6732eec75b2ea25d349df4f76c84a7fc51443f55712c47b0ae0f7a049d7ae19f328ca504ded1f6df00861c725dcfdbeaac07c3bd999c5f3b')

prepare() {
  cd tomlkit-$pkgver
  dephell deps convert --from pyproject.toml --to setup.py
  rmdir tests/toml-test
  ln -s "$srcdir"/toml-test-$_tomltestcommit tests/toml-test
}

build() {
  cd tomlkit-$pkgver
  python setup.py build
}

check() {
  cd tomlkit-$pkgver
  python -m pytest
}

package() {
  cd tomlkit-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
