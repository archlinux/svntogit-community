# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-pytest-runner
pkgname=('python-pytest-runner' 'python2-pytest-runner')
pkgver=5.2
pkgrel=1
pkgdesc="Invoke py.test as distutils command with dependency resolution"
arch=('any')
license=('MIT')
url="https://github.com/pytest-dev/pytest-runner"
makedepends=('python-pytest' 'python2-pytest' 'python-setuptools-scm' 'python2-setuptools-scm')
checkdepends=('python-pytest-black' 'python-pytest-cov' 'python-pytest-virtualenv'
              'python-pytest-flake8')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/pytest-dev/pytest-runner/archive/$pkgver.tar.gz")
sha512sums=('0ce9c191481ab97795d0f45bdea7669cb61c3ac6aac476954d34c3e09e6fb08fd6bf73f192c014cb7ff2bd90dbfeb0f01d9a9ba7a9c6caeb371e40b42b558d63')

prepare() {
  cp -a pytest-runner-$pkgver{,-py2}

  export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver
}

build() {
  cd "$srcdir"/pytest-runner-$pkgver
  python setup.py build

  cd "$srcdir"/pytest-runner-$pkgver-py2
  python2 setup.py build
}

check() {
  cd pytest-runner-$pkgver
  python setup.py egg_info
  PYTHONPATH="$PWD" pytest
}

package_python-pytest-runner() {
  depends=('python-pytest')

  cd pytest-runner-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

package_python2-pytest-runner() {
  depends=('python2-pytest')

  cd pytest-runner-$pkgver-py2
  python2 setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
