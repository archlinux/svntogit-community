# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: Sébastien "Seblu" Luttringer

pkgname=python-msgpack
pkgver=1.0.5
pkgrel=1
pkgdesc='MessagePack serializer implementation for Python'

url='https://github.com/msgpack/msgpack-python'
arch=('x86_64')
license=('Apache')


depends=('python')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest' 'python-six')

source=(msgpack-python-$pkgver.tar.gz::https://github.com/msgpack/msgpack-python/archive/v$pkgver.tar.gz)

sha512sums=('0d0b479044cda16519cf85d45acb8900b6e6585bf95816396fc96d6d1eb260036fb9c75bf8f88d99e212937a40d314a200d2b847d1da8a9ebc5694ab52e22896')

build() {
  cd msgpack-python-$pkgver
  python setup.py build
}

check() {
  cd msgpack-python-$pkgver
  PYTHONDONTWRITEBYTECODE=1 PYTHONPATH=$(printf '%s\n' $PWD/build/* | paste -sd:) py.test test
}

package() {
  cd msgpack-python-$pkgver
  python setup.py install --skip-build --root="$pkgdir" --optimize=1
}

# vim:set ts=2 sw=2 et:
