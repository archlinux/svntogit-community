# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-importlib-metadata
pkgver=4.6.1
pkgrel=1
pkgdesc="Read metadata from Python packages"
url="https://importlib-metadata.readthedocs.io"
license=('Apache')
arch=('any')
depends=('python-zipp')
makedepends=('python-setuptools-scm' 'python-toml' 'python-wheel')
checkdepends=('python-pip' 'python-pytest' 'python-importlib_resources'
              'python-pyfakefs' 'python-tests')
source=("https://github.com/python/importlib_metadata/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('1e498885c1100a1e05f3548c0064a63520000ad18157837948f76b1108eb197e4f653d160a6420f790280c38a17f8f89404f1af5193916736e26e99ff9e77db3')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

prepare() {
  # remove pytest-perf warmup to be able to drop its dependency
  rm importlib_metadata-$pkgver/exercises.py
}

build() {
  cd importlib_metadata-$pkgver
  python setup.py build
}

check() {
  cd importlib_metadata-$pkgver
  python -m pytest -k 'not test_find_local'
}

package_python-importlib-metadata() {
  cd importlib_metadata-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}
