# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: Sébastien "Seblu" Luttringer

pkgname=python-msgpack
pkgver=1.0.3
pkgrel=1
pkgdesc='MessagePack serializer implementation for Python'

url='https://github.com/msgpack/msgpack-python'
arch=('x86_64')
license=('Apache')


depends=('python')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest' 'python-six')

source=(msgpack-python-$pkgver.tar.gz::https://github.com/msgpack/msgpack-python/archive/v$pkgver.tar.gz)

sha512sums=('ff8278d8a3cf001fe19660a8affe3ca33229a69b20389ca04a1d8c0ab92da7013dc9da70517d0a29358c9faf0e85e0339929aab423f521d2664bd198a7c2d738')

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
