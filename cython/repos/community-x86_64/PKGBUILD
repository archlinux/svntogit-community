# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Igor Scabini <furester @ gmail.com>

pkgname=(cython cython2)
pkgbase=cython
pkgver=0.29.5
pkgrel=1
pkgdesc="C-Extensions for Python"
arch=(x86_64)
url="https://cython.org"
license=(APACHE)
makedepends=(python-setuptools python2-setuptools)
source=($pkgbase-$pkgver.tar.gz::"https://github.com/cython/cython/archive/$pkgver.tar.gz")
sha256sums=('2107bf85ed2cfeab635f65d583d1450599b77fa1e041db9de49caccc5c644f67')

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
