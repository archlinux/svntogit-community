# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: Sébastien "Seblu" Luttringer

pkgbase=python-msgpack
pkgname=('python-msgpack' 'python2-msgpack')
pkgver=0.6.2
pkgrel=1

url='https://github.com/msgpack/msgpack-python'
arch=('x86_64')
license=('Apache')

makedepends=('cython' 'cython2' 'python-setuptools' 'python2-setuptools')
checkdepends=('python-pytest' 'python2-pytest' 'python-six' 'python2-six')

source=(msgpack-python-$pkgver.tar.gz::https://github.com/msgpack/msgpack-python/archive/v$pkgver.tar.gz)

md5sums=('e751675f8e18625bf1d2ec391dd9e8fd')

build() {
  cd msgpack-python-$pkgver
  python setup.py build --build-lib=build/python
  python2 setup.py build --build-lib=build/python2
  find build/python2 -type f -exec \
    sed -i '1s,^#! \?/usr/bin/\(env \|\)python$,#!/usr/bin/python2,' {} \;
}

check() {
  cd msgpack-python-$pkgver
  PYTHONPATH=$PWD/build/python py.test test
  PYTHONPATH=$PWD/build/python2 py.test2 test
}

package_python-msgpack() {
  pkgdesc='MessagePack serializer implementation for Python'
  depends=('python')

  cd msgpack-python-$pkgver
  python setup.py build --build-lib=build/python \
                  install --root="$pkgdir" --optimize=1
}

package_python2-msgpack() {
  pkgdesc='MessagePack serializer implementation for Python2'
  depends=('python2')

  cd msgpack-python-$pkgver
  python2 setup.py build --build-lib=build/python2 \
                   install --root="$pkgdir" --optimize=1
}

# vim:set ts=2 sw=2 et:
