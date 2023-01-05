# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Igor Scabini <furester @ gmail.com>

pkgname=cython
pkgver=0.29.33
pkgrel=1
pkgdesc='C-Extensions for Python'
arch=(x86_64)
url='https://cython.org'
license=(APACHE)
makedepends=(python-setuptools)
source=(https://github.com/cython/cython/archive/$pkgver/$pkgbase-$pkgver.tar.gz)
sha256sums=('f1c07848de6c1bbe995c2bdbe237e558fd08747568b9503b079aae661fb8d99f')

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
