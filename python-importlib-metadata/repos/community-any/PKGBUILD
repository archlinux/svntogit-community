# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-importlib-metadata
pkgver=3.7.2
pkgrel=1
pkgdesc="Read metadata from Python packages"
url="https://importlib-metadata.readthedocs.io"
license=('Apache')
arch=('any')
depends=('python-zipp')
makedepends=('python-setuptools-scm' 'python-wheel')
checkdepends=('python-pip' 'python-pytest' 'python-importlib_resources'
              'python-pyfakefs' 'python-tests')
source=("$pkgname-$pkgver.tar.gz::https://github.com/python/importlib_metadata/archive/v$pkgver.tar.gz")
sha512sums=('63372d85f3f049b986755036e2b699c6a43cd50aba85b9381a863e941f37e5780fde35ed1065198c2ecb2d3c7a3a720033c04106de6fd1fe5da5e466f2e374f1')


build() {
  cd importlib_metadata-$pkgver

  export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

  python setup.py build
}

check() {
  cd importlib_metadata-$pkgver
  python -m pytest -k 'not test_find_local'
}

package_python-importlib-metadata() {
  cd importlib_metadata-$pkgver

  export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

  python setup.py install --root="$pkgdir" --optimize=1
}

