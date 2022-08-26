# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-importlib-metadata
pkgver=4.8.2
pkgrel=1
pkgdesc="Read metadata from Python packages"
url="https://importlib-metadata.readthedocs.io"
license=('Apache')
arch=('any')
depends=('python-zipp')
makedepends=('python-setuptools-scm' 'python-toml')
checkdepends=('python-pip' 'python-pytest' 'python-importlib_resources'
              'python-pyfakefs' 'python-tests')
source=("https://github.com/python/importlib_metadata/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('f9d7f529d879d3ac619aef0ad464de57045bb74a6c73c88d1f18bafad4eb3645a313e93b51cb4f8ba176d124a4386d2e6854937c568fd7c232f62ef681322fdc')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

build() {
  cd importlib_metadata-$pkgver
  python setup.py build
}

check() {
  cd importlib_metadata-$pkgver
  python -m pytest --ignore exercises.py
}

package_python-importlib-metadata() {
  cd importlib_metadata-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}
