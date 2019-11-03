# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-pytest-runner
pkgname=('python-pytest-runner' 'python2-pytest-runner')
pkgver=5.1
pkgrel=3
pkgdesc="Invoke py.test as distutils command with dependency resolution"
arch=('any')
license=('MIT')
url="https://github.com/pytest-dev/pytest-runner"
makedepends=('python-pytest' 'python2-pytest' 'python-setuptools-scm' 'python2-setuptools-scm')
checkdepends=('python-pytest-black' 'python-pytest-virtualenv' 'python-pytest-flake8')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/pytest-dev/pytest-runner/archive/$pkgver.tar.gz")
sha512sums=('79806b6370e2378b5f230181e265e3046739ebc3ece729d1e3805510b5fb2d34022d60b9071a5a036f3b2604ffedf14b403e9910f0c56a58adc5c51c84866146')

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
