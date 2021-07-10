# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-importlib-metadata
pkgver=4.6.0
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
sha512sums=('41bed26e8ca921d86ba529d318dda26d04a3d66aa16334aa1e980b586872321a6d9d5bc7030a66ff5a7a5994e62f7b8b999a8b9b47dd2c4496486df6f138767b')

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

