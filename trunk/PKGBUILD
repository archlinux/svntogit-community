# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Lance Chen <cyen0312@gmail.com>

_pypiname=wheel
pkgbase=python-wheel
pkgname=('python-wheel' 'python2-wheel')
pkgver=0.37.0
pkgrel=2
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
sha512sums=('2e0eb1c5560a0229be9de450da8b2bc62153744abb6d8ab9a0625c150dc00d3fc3e24dbe37cc26f4ca6b6876b5c63298427b2076ee42b8f772c75010bfc135a8')

prepare() {
  # don't depend on python-coverage for tests
  sed -i 's/--cov=wheel//' wheel-$pkgver/setup.cfg

  # https://github.com/pypa/wheel/pull/365 but why?
  rm -r wheel-$pkgver/src/wheel/vendored
  sed -i 's/from .vendored.packaging import tags/from packaging import tags/' wheel-$pkgver/src/wheel/bdist_wheel.py

  cp -a wheel-$pkgver{,-py2}
}

build() {
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
  optdepends=('python-keyring: for wheel.signatures'
              'python-xdg: for wheel.signatures')

  cd "$srcdir/$_pypiname-$pkgver"
  python setup.py install --root="$pkgdir/" --optimize=1 --skip-build
  install -D -m644 LICENSE.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE.txt"
}

package_python2-wheel() {
  depends=('python2-packaging')
  cd "$srcdir/$_pypiname-$pkgver"
  python2 setup.py install --root="$pkgdir/" --optimize=1 --skip-build
  install -D -m644 LICENSE.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE.txt"
  mv "$pkgdir/usr/bin/wheel" "$pkgdir/usr/bin/wheel2"
}

# vim:set ts=2 sw=2 et:
