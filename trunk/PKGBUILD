# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=tomlkit
pkgname=python-tomlkit
pkgver=0.7.1
_testcommit=f910e151d1b14d94b1e8a4264db0814fb03520d9
pkgrel=1
pkgdesc="Style-preserving TOML library for Python"
url="https://github.com/sdispater/tomlkit"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('python-dephell')
checkdepends=('python-pytest' 'python-yaml')
source=("https://files.pythonhosted.org/packages/source/${_pkgname:0:1}/${_pkgname}/${_pkgname}-${pkgver}.tar.gz"
        https://github.com/BurntSushi/toml-test/archive/$_testcommit/toml-test-$_testcommit.tar.gz)
sha512sums=('a62b49e7ec37a2cdb13f7de83ffca734fdf53d5ade7b666194f62d6fb7ccc3df0533c4c5c8585b3213ed9886ab495107f457607c9f29ec9b3d1ced042a0e2b03'
            '49431bf72cd5b40b6732eec75b2ea25d349df4f76c84a7fc51443f55712c47b0ae0f7a049d7ae19f328ca504ded1f6df00861c725dcfdbeaac07c3bd999c5f3b')

prepare() {
  cd tomlkit-$pkgver

  # poetry-generated setup.py is badly broken in several ways, including
  # distribution of tests in the built package as well as using distutils for
  # bad metadata. See https://github.com/sdispater/poetry/issues/866
  dephell deps convert --from pyproject.toml --to setup.py

  # Since 0.7.1 toml-test is no longer included in pypi tarball
  ln -s "$srcdir"/toml-test-$_testcommit tests/toml-test
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
