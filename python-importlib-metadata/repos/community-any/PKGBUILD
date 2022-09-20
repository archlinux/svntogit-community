# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-importlib-metadata
pkgver=4.9.0
pkgrel=1
pkgdesc="Read metadata from Python packages"
url="https://importlib-metadata.readthedocs.io"
license=('Apache')
arch=('any')
depends=('python-zipp')
makedepends=('python-setuptools-scm')
checkdepends=('python-pytest' 'python-pep517' 'python-pyfakefs' 'python-pip' 'python-tests')
source=("https://github.com/python/importlib_metadata/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('1abf8f0a66aad818c10a314bb86511838164aedf72c6abbdcc14c5b60ac5fac62ebc530ced477314da57b48c3a75e3a4525f0ebab6cf96f4cf096d9046575fa6')

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
