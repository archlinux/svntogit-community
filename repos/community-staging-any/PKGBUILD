# Maintainer: Thomas Dziedzic < gostrc at gmail >
# Contributor: Pierre Chapuis <catwell at archlinux dot us>

_name=decorator
pkgname=('python-decorator' 'python2-decorator')
pkgver=4.4.0
pkgrel=3
pkgdesc='Python Decorator module'
arch=('any')
url='https://pypi.python.org/pypi/decorator'
license=('BSD')
makedepends=('python2' 'python' 'python-setuptools' 'python2-setuptools')
source=("https://pypi.python.org/packages/source/${_name:0:1}/${_name}/${_name}-${pkgver}.tar.gz"
        'LICENSE.txt')
sha512sums=('32c35c80581cb7fd0b2461d21c7eb14190294b2ccc9f92749b6bc74449f7d02a26281e9a2817f6f16871a6cddb7b02b8fae8119c22256fe43a6aaa31a7599dd5'
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
