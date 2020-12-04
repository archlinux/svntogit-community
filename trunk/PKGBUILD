# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Lance Chen <cyen0312@gmail.com>

_pypiname=wheel
pkgbase=python-wheel
pkgname=('python-wheel' 'python2-wheel')
pkgver=0.36.1
pkgrel=1
pkgdesc="A built-package format for Python"
arch=(any)
url="https://pypi.python.org/pypi/wheel"
license=('MIT')
makedepends=('python-packaging' 'python-setuptools'
             'python2-packaging' 'python2-setuptools')
checkdepends=('python-jsonschema' 'python-pytest' 'python-keyring' 'python-keyrings-alt'
              'python-xdg')
source=("https://pypi.io/packages/source/w/wheel/$_pypiname-$pkgver.tar.gz")
source=("$pkgname-$pkgver.tar.gz::https://github.com/pypa/wheel/archive/$pkgver.tar.gz")
sha512sums=('1f9a27604b0fa0d1ae4782bdba57956a70d74a9a736f4c41481b417cd1e8a86938705555c37835ffe1a061ef55f8adad3475bfc20e2c1fd8de8083dd5c72cca0')

prepare() {
  # don't depend on python-coverage for tests
  sed -i 's/--cov=wheel//' wheel-$pkgver/setup.cfg

  # https://github.com/pypa/wheel/pull/365 but why?
  rm -r wheel-$pkgver/src/wheel/vendored
  sed -i 's/from .vendored.packaging import tags/from packaging import tags/' wheel-$pkgver/src/wheel/bdist_wheel.py

  cp -a wheel-$pkgver{,-py2}
}

build() {
  export PYTHONHASHSEED=0

  cd "$srcdir/wheel-$pkgver"
  python setup.py build

  cd "$srcdir/wheel-$pkgver-py2"
  python2 setup.py build
}

check() {
  # Hack entry points by installing it

  cd wheel-$pkgver
  python setup.py install --root="$PWD/tmp_install" --optimize=1
  PYTHONPATH="$PWD/tmp_install/usr/lib/python3.9/site-packages:$PYTHONPATH" py.test
}

package_python-wheel() {
  depends=('python-packaging')
  optdepends=('python-keyring: for wheel.signatures')
  optdepends=('python-xdg: for wheel.signatures')

  cd "$srcdir/$_pypiname-$pkgver"
  python setup.py install --root="$pkgdir/" --optimize=1 --skip-build
  install -D -m644 LICENSE.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE.txt"
}

package_python2-wheel() {
  depends=('python2-packaging')
  optdepends=('python2-keyring: for wheel.signatures')
  optdepends=('python2-xdg: for wheel.signatures')

  cd "$srcdir/$_pypiname-$pkgver"
  python2 setup.py install --root="$pkgdir/" --optimize=1 --skip-build
  install -D -m644 LICENSE.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE.txt"
  mv "$pkgdir/usr/bin/wheel" "$pkgdir/usr/bin/wheel2"
}

# vim:set ts=2 sw=2 et:
