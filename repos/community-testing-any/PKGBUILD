# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: codedust
# Contributor: Dario Ostuni <dario.ostuni@gmail.com>
# Contributor: Clayton Craft <clayton at craftyguy dot net>

pkgname=python-setuptools-rust
pkgver=0.12.1
pkgrel=3
pkgdesc="Compile and distribute Python extensions written in rust as easily as if they were written in C."
arch=('any')
license=('MIT')
url="https://github.com/PyO3/setuptools-rust"
depends=('rust' 'python-setuptools' 'python-semantic-version' 'python-toml')
makedepends=('python-setuptools-scm' 'python-wheel')
checkdepends=('python-pytest' 'python-pytest-benchmark' 'python-beautifulsoup4' 'python-lxml' 'python-cffi')
source=("https://github.com/PyO3/setuptools-rust/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('6cff0ad83026cbc548cc0fc20b7456e1555893b0fb670756409bc351ebaae7e2f4bad17c8379cad50120665669f409c14b35f80491c7d6f6ad9768b63cb7cf11')

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
    [[ -d tests || -d test ]] && PYTHONPATH="$PWD/build/lib:build/lib.linux-$CARCH-3.10" pytest
    popd
  done
}

package() {
  cd setuptools-rust-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
