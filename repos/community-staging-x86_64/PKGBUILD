# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Igor Scabini <furester @ gmail.com>

pkgname=cython
pkgver=0.29.34
pkgrel=3
pkgdesc='C-Extensions for Python'
arch=(x86_64)
url='https://cython.org'
license=(APACHE)
makedepends=(python-setuptools)
source=(https://github.com/cython/cython/archive/$pkgver/$pkgbase-$pkgver.tar.gz)
sha256sums=('6428ed43b8d0edd961e0b45502a0b1e64059d84a0ed2abb84d20e9a6d9047dc6')

build() {
  cd cython-$pkgver
  python setup.py build
}

package() {
  cd cython-$pkgver
  python setup.py install --root="$pkgdir" --skip-build

  for f in cygdb cython cythonize; do
    mv "$pkgdir"/usr/bin/$f "$pkgdir"/usr/bin/${f}3
    ln -s ${f}3 "$pkgdir"/usr/bin/$f
  done
}
