# Maintainer: Thomas Dziedzic < gostrc at gmail >
# Contributor: Pierre Chapuis <catwell at archlinux dot us>

pkgname=python-decorator
pkgver=3.2.0
pkgrel=1
pkgdesc='Python Decorator module'
arch=('any')
url='http://pypi.python.org/pypi/decorator'
license=('BSD')
depends=('python')
source=("http://pypi.python.org/packages/source/d/decorator/decorator-${pkgver}.tar.gz"
        'LICENSE.txt')
md5sums=('6208cd51365083c168ab3a04426a646b'
         '0ca76d2c707f09dbb04acc425ea1a08b')

build() {
  cd decorator-${pkgver}

  python setup.py build
}

package() {
  cd decorator-${pkgver}

  python setup.py install --root=${pkgdir} --optimize=1

  install -D -m644 ${srcdir}/LICENSE.txt ${pkgdir}/usr/share/licenses/${pkgname}/LICENSE
}
