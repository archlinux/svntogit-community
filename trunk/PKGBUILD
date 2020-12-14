# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-importlib-metadata
pkgver=3.3.0
pkgrel=1
pkgdesc="Read metadata from Python packages"
url="https://importlib-metadata.readthedocs.io"
license=('Apache')
arch=('any')
depends=('python-zipp')
makedepends=('python-setuptools-scm')
checkdepends=('python-pip' 'python-pytest-runner' 'python-importlib_resources'
              'python-wheel' 'python-pyfakefs' 'python-tests')
source=("$pkgname-$pkgver.tar.gz::https://github.com/python/importlib_metadata/archive/v$pkgver.tar.gz")
sha512sums=('965099dc835fd76ed35041071bdd0233dc773468506cdbdee595289292dbf5cb76232f98663dbf11ab5ac4bf6cc8f484a7e6fb7343a899488deaf1f3098b57ca')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

build() {
  cd importlib_metadata-$pkgver
  python setup.py build
}

check() {
  cd importlib_metadata-$pkgver
  python setup.py pytest
}

package_python-importlib-metadata() {
  cd importlib_metadata-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}

