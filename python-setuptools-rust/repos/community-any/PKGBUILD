# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: codedust
# Contributor: Dario Ostuni <dario.ostuni@gmail.com>
# Contributor: Clayton Craft <clayton at craftyguy dot net>

pkgname=python-setuptools-rust
pkgver=1.3.0
pkgrel=1
pkgdesc="Compile and distribute Python extensions written in rust as easily as if they were written in C."
arch=('any')
license=('MIT')
url="https://github.com/PyO3/setuptools-rust"
depends=('rust' 'python-setuptools' 'python-semantic-version' 'python-typing-extensions')
makedepends=('python-setuptools-scm' 'python-wheel')
checkdepends=('python-pytest' 'python-pytest-benchmark' 'python-beautifulsoup4' 'python-lxml' 'python-cffi')
source=("https://github.com/PyO3/setuptools-rust/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('e9259befb38ee22d355c9dcebc4cb5dd0d23b7a00ac9be16ce61f8c11bd0cee3a2afd2099f8882e9224475d084a61c1721cfee48200d7b061bffa631380d73b4')

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
