# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-pytest-runner
pkgname=('python-pytest-runner' 'python2-pytest-runner')
pkgver=4.4
pkgrel=1
pkgdesc="Invoke py.test as distutils command with dependency resolution"
arch=('any')
license=('MIT')
url="https://github.com/pytest-dev/pytest-runner"
makedepends=('python-pytest' 'python2-pytest' 'python-setuptools-scm' 'python2-setuptools-scm')
checkdepends=('python-pytest-virtualenv' 'python2-pytest-virtualenv' 'python-pytest-flake8'
              'python2-pytest-flake8')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/pytest-dev/pytest-runner/archive/$pkgver.tar.gz")
sha512sums=('a369bea32accebc0cb1184ca6fbc7c73c9385c2745f14e1102c3da96ce0a41b901d0b20eaef1e0eecb06f448414624b3edb14f34829c1dc8953c0d472dc38862')

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
