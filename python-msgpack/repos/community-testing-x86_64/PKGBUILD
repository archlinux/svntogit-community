# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: Sébastien "Seblu" Luttringer

pkgname=python-msgpack
pkgver=1.0.0
pkgrel=3
pkgdesc='MessagePack serializer implementation for Python'

url='https://github.com/msgpack/msgpack-python'
arch=('x86_64')
license=('Apache')


depends=('python')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest' 'python-six')

source=(msgpack-python-$pkgver.tar.gz::https://github.com/msgpack/msgpack-python/archive/v$pkgver.tar.gz)

sha512sums=('ef392d9084ff9a86cc69514982f10d9c39494a9d2c56cd1904b75a6e493d2673ab4e47261464af07dd7beaaba153fe008a9917332e1a4c96beef4ba9ebe595ab')

build() {
  cd msgpack-python-$pkgver
  python setup.py build --build-lib=build/python
}

check() {
  cd msgpack-python-$pkgver
  PYTHONPATH=$PWD/build/python py.test test
}

package() {
  cd msgpack-python-$pkgver
  python setup.py build --build-lib=build/python \
                  install --root="$pkgdir" --optimize=1
}

# vim:set ts=2 sw=2 et:
