# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-pytest-runner
pkgname=('python-pytest-runner' 'python2-pytest-runner')
pkgver=4.3.1
pkgrel=1
pkgdesc="Invoke py.test as distutils command with dependency resolution"
arch=('any')
license=('MIT')
url="https://github.com/pytest-dev/pytest-runner"
makedepends=('python-pytest' 'python2-pytest' 'python-setuptools-scm' 'python2-setuptools-scm')
checkdepends=('python-pytest-virtualenv' 'python2-pytest-virtualenv' 'python-pytest-flake8'
              'python2-pytest-flake8')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/pytest-dev/pytest-runner/archive/$pkgver.tar.gz")
sha512sums=('a5a5069e728a891f2156d5e52233a9f16fcb483038dd2a6f77796c08e88493bd253d98db2c6027f3004cb146f0eda841e8e003972c68e1b1bfa462c7b3de15cb')

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
  cd "$srcdir"/pytest-runner-$pkgver
  python setup.py egg_info
  PYTHONPATH="$PWD" pytest

  cd "$srcdir"/pytest-runner-$pkgver-py2
  python2 setup.py egg_info
  PYTHONPATH="$PWD" pytest2
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
