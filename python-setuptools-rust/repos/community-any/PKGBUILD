# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: codedust
# Contributor: Dario Ostuni <dario.ostuni@gmail.com>
# Contributor: Clayton Craft <clayton at craftyguy dot net>

pkgname=python-setuptools-rust
pkgver=1.1.2
pkgrel=1
pkgdesc="Compile and distribute Python extensions written in rust as easily as if they were written in C."
arch=('any')
license=('MIT')
url="https://github.com/PyO3/setuptools-rust"
depends=('rust' 'python-setuptools' 'python-semantic-version' 'python-typing-extensions')
makedepends=('python-setuptools-scm' 'python-wheel')
checkdepends=('python-pytest' 'python-pytest-benchmark' 'python-beautifulsoup4' 'python-lxml' 'python-cffi')
source=("https://github.com/PyO3/setuptools-rust/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('203462bc02d2891906779276da1859a31f26c8cb16e8e4b85bf082dca48999eef848cc41447952ce90eafd35022cbd5cddb9ea7b5087f94af977bd7e4ea38a27')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

build() {
  cd setuptools-rust-$pkgver
  python setup.py build
}

check() {
  cd setuptools-rust-$pkgver
  python setup.py egg_info
  for _dir in examples/*; do
    pushd $_dir
    PYTHONPATH="$PWD/../.." python setup.py build
    [[ -d tests || -d test ]] && PYTHONPATH="$PWD/build/lib:build/lib.linux-$CARCH-cpython-310" pytest
    popd
  done
  pytest --doctest-modules setuptools_rust
}

package() {
  cd setuptools-rust-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
