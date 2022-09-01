# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: codedust
# Contributor: Dario Ostuni <dario.ostuni@gmail.com>
# Contributor: Clayton Craft <clayton at craftyguy dot net>

pkgname=python-setuptools-rust
pkgver=1.1.1
pkgrel=1
pkgdesc="Compile and distribute Python extensions written in rust as easily as if they were written in C."
arch=('any')
license=('MIT')
url="https://github.com/PyO3/setuptools-rust"
depends=('rust' 'python-setuptools' 'python-semantic-version' 'python-tomli' 'python-typing-extensions')
makedepends=('python-setuptools-scm' 'python-wheel')
checkdepends=('python-pytest' 'python-pytest-benchmark' 'python-beautifulsoup4' 'python-lxml' 'python-cffi')
source=("https://github.com/PyO3/setuptools-rust/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('a580c7283074f516251386c0dc3f9e7cc770bb8760bc9ce7b263e1db93bae99c1f1de0d31ceb2038b9163002c9a2ccd5f443f5112187021c9bd692e53ea0b99f')

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
