# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Lance Chen <cyen0312@gmail.com>

_pypiname=wheel
pkgname=python-wheel
pkgver=0.38.0
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
sha512sums=('0ffdf531c03d1f0866632002b163fdf8642b613604e74d1cfa5844e8c327946baf303bc0410fc7ec034f8a79cb4ad59536dfdaaa5cc8fa23a3b7d21faf5e6161')

prepare() {
  # don't depend on python-coverage for tests
  sed -i 's/--cov=wheel//' wheel-$pkgver/setup.cfg

  # https://github.com/pypa/wheel/pull/365 but why?
  rm -r wheel-$pkgver/src/wheel/vendored
  sed -i 's/from .vendored.packaging import tags/from packaging import tags/' wheel-$pkgver/src/wheel/bdist_wheel.py
}

build() {
  cd "$srcdir/wheel-$pkgver"
  python setup.py build
}

check() {
  # Hack entry points by installing it

  cd wheel-$pkgver
  python setup.py install --root="$PWD/tmp_install" --optimize=1
  PYTHONPATH="$PWD/tmp_install/usr/lib/python3.10/site-packages:$PYTHONPATH" py.test
}

package() {
  cd "$srcdir/$_pypiname-$pkgver"
  python setup.py install --root="$pkgdir/" --optimize=1 --skip-build
  install -D -m644 LICENSE.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE.txt"
}
