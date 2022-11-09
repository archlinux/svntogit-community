# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Lance Chen <cyen0312@gmail.com>

_pypiname=wheel
pkgname=python-wheel
pkgver=0.38.2
pkgrel=1
pkgdesc="A built-package format for Python"
arch=(any)
url="https://pypi.python.org/pypi/wheel"
license=('MIT')
depends=('python-packaging')
optdepends=('python-keyring: for wheel.signatures'
            'python-xdg: for wheel.signatures')
makedepends=('python-setuptools')
checkdepends=('python-jsonschema' 'python-pytest' 'python-keyring' 'python-keyrings-alt'
              'python-xdg' 'python-pytest-cov')
source=("$pkgname-$pkgver.tar.gz::https://github.com/pypa/wheel/archive/$pkgver.tar.gz")
sha512sums=('59a55e35f641dc6e97bcd58755ef39dd771f8ed442843321878054db3c54234befde368ae500a93fffde6ea1bbcb0e3981975b2c7574fc5a58693a70430e474b')

prepare() {
  cd wheel-$pkgver
  # don't depend on python-coverage for tests
  sed -i 's/--cov=wheel//' setup.cfg

  # https://github.com/pypa/wheel/pull/365 but why?
  rm -r src/wheel/vendored
  sed -i 's/from .vendored.packaging import tags/from packaging import tags/' src/wheel/bdist_wheel.py
  sed -i 's/from wheel.vendored.packaging import tags/from packaging import tags/' tests/test_bdist_wheel.py
}

build() {
  cd wheel-$pkgver
  python setup.py build
}

check() {
  # Hack entry points by installing it

  cd wheel-$pkgver
  python setup.py install --root="$PWD/tmp_install" --optimize=1
  PYTHONPATH="$PWD/tmp_install/usr/lib/python3.10/site-packages" pytest
}

package() {
  cd wheel-$pkgver
  python setup.py install --root="$pkgdir/" --optimize=1 --skip-build
  install -Dm644 LICENSE.txt -t "$pkgdir"/usr/share/licenses/$pkgname/
}
