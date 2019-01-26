# Maintainer: Thomas Dziedzic < gostrc at gmail >
# Contributor: Pierre Chapuis <catwell at archlinux dot us>

_name=decorator
pkgname=('python-decorator' 'python2-decorator')
pkgver=4.3.2
pkgrel=1
pkgdesc='Python Decorator module'
arch=('any')
url='http://pypi.python.org/pypi/decorator'
license=('BSD')
makedepends=('python2' 'python' 'python-setuptools' 'python2-setuptools')
source=("https://pypi.python.org/packages/source/${_name:0:1}/${_name}/${_name}-${pkgver}.tar.gz"
        'LICENSE.txt')
sha512sums=('87102e1b314086d008c48bf53f1061b28fdbd3ccd3d301773102fd43e3a4ce8b5ffeb9107fb5d5f47b7bd45c26e5b3b2913ea20745ffc9b274e2c0b24a69ef70'
            '0a06dfb3f470b8d3b056bd4e4776df715876d04d0acc86dec536fa7cff0214ba5255833923558d1778db730d080960f31d5e12f939e761530823b6e70646b5c2')

build() {
  # Make python and python2 builds possible
  cp -r decorator-$pkgver decorator2-$pkgver

  cd "$srcdir/$_name-$pkgver"

  python3 setup.py build

  cd "$srcdir/${_name}2-$pkgver"

  python2 setup.py build
}

package_python2-decorator() {
depends=('python2')
replaces=('python-decorator<=3.3.2-1')
  cd "${srcdir}/${_name}2-${pkgver}"

  python2 setup.py install --root="${pkgdir}" --optimize=1

  install -D -m644 "${srcdir}/LICENSE.txt" \
    "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
package_python-decorator() {
depends=('python')
  cd "${srcdir}/${_name}-${pkgver}"

  python3 setup.py install --root="${pkgdir}" --optimize=1

  install -D -m644 "${srcdir}/LICENSE.txt" \
    "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}

check() {
  cd "$srcdir/${_name}-$pkgver"

  python3 setup.py test

  cd "$srcdir/${_name}2-$pkgver"

  python2 setup.py test
}
