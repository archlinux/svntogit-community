# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Igor Scabini <furester @ gmail.com>

pkgname=(cython cython2)
pkgbase=cython
pkgver=0.29.25
pkgrel=3
pkgdesc='C-Extensions for Python'
arch=(x86_64)
url='https://cython.org'
license=(APACHE)
makedepends=(python-setuptools python2-setuptools)
source=(https://github.com/cython/cython/archive/$pkgver/$pkgbase-$pkgver.tar.gz)
sha256sums=('dcee4374bff7a0fbd6802dacaf77b2edb1c1324380f11b8646acae9f9efa4fcc')

prepare() {
  cp -r cython-$pkgver cython2-$pkgver
  find cython2-$pkgver -name '*.py' | xargs sed -e 's|/usr/bin/env python|/usr/bin/env python2|' -e 's|/usr/bin/python|/usr/bin/python2|' -i
}

build() {
  cd cython-$pkgver
  python setup.py build

  cd ../cython2-$pkgver
  python2 setup.py build
}

package_cython() {
  depends=(python)

  cd cython-$pkgver
  python setup.py install --root="$pkgdir" --skip-build

  for f in cygdb cython cythonize; do
    mv "$pkgdir"/usr/bin/$f "$pkgdir"/usr/bin/${f}3
    ln -s ${f}3 "$pkgdir"/usr/bin/$f
  done
}

package_cython2() {
  depends=(python2)

  cd cython2-$pkgver
  python2 setup.py install --root="$pkgdir" --skip-build

  for f in cygdb cython cythonize; do
    mv "$pkgdir"/usr/bin/$f "$pkgdir"/usr/bin/${f}2
  done
}
