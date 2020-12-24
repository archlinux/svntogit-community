# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: Sébastien "Seblu" Luttringer

pkgname=python-msgpack
pkgver=1.0.2
pkgrel=1
pkgdesc='MessagePack serializer implementation for Python'

url='https://github.com/msgpack/msgpack-python'
arch=('x86_64')
license=('Apache')


depends=('python')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest' 'python-six')

source=(msgpack-python-$pkgver.tar.gz::https://github.com/msgpack/msgpack-python/archive/v$pkgver.tar.gz)

sha512sums=('8e53c57312beed0cbc24b681b605fa8b832469b1aab035aaa187b2887e7865ff653a3f358dab2f3e773c657cf0af4264d4e530639ef23934d4b95d9fa2a7ee9a')

prepare() {
  cd msgpack-python-$pkgver
  printf '[build]\nbuild_lib = build/lib.linux' >> setup.cfg
}

build() {
  cd msgpack-python-$pkgver
  python setup.py build
}

check() {
  cd msgpack-python-$pkgver
  PYTHONPATH=$PWD/build/lib.linux py.test test
}

package() {
  cd msgpack-python-$pkgver
  export PYTHONHASHSEED=0
  python setup.py install --skip-build --root="$pkgdir" --optimize=1
}

# vim:set ts=2 sw=2 et:
