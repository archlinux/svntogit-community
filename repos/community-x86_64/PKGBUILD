# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Igor Scabini <furester @ gmail.com>

pkgname=(cython cython2)
pkgbase=cython
pkgver=0.29.21
pkgrel=1
pkgdesc="C-Extensions for Python"
arch=(x86_64)
url="https://cython.org"
license=(APACHE)
makedepends=(python-setuptools python2-setuptools)
source=($pkgbase-$pkgver.tar.gz::"https://github.com/cython/cython/archive/$pkgver.tar.gz"
        cython-hash-int-conversion.patch::"https://github.com/cython/cython/commit/28251032.patch")
sha256sums=('e2e38e1f0572ca54d6085df3dec8b607d20e81515fb80215aed19c81e8fe2079'
            '28b2b065a9853e86d0bc09287e8a21f50ebc1f3cfee3b2ab03b6b917cb9e81d8')

prepare() {
  cp -r cython-$pkgver cython2-$pkgver
  find cython2-$pkgver -name '*.py' | xargs sed -e 's|/usr/bin/env python|/usr/bin/env python2|' -e 's|/usr/bin/python|/usr/bin/python2|' -i

  cd cython-$pkgver
  patch -p1 -i ../cython-hash-int-conversion.patch # Allow non-int conversion to Py_hash_t, needed by sagemath
}

build() {
  cd cython-$pkgver
  python setup.py build

  cd ../cython2-$pkgver
  python2 setup.py build
}

package_cython() {
  depends=(python-setuptools)

  cd cython-$pkgver
  python setup.py install --root="$pkgdir" --skip-build

  for f in cygdb cython cythonize; do
    mv "$pkgdir"/usr/bin/$f "$pkgdir"/usr/bin/${f}3
    ln -s ${f}3 "$pkgdir"/usr/bin/$f
  done
}

package_cython2() {
  depends=(python2-setuptools)

  cd cython2-$pkgver
  python2 setup.py install --root="$pkgdir" --skip-build

  for f in cygdb cython cythonize; do
    mv "$pkgdir"/usr/bin/$f "$pkgdir"/usr/bin/${f}2
  done
}
