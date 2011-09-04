# Maintainer: Thomas Dziedzic < gostrc at gmail >
# Contributor: Pierre Chapuis <catwell at archlinux dot us>

pkgname=python-decorator
pkgver=3.3.1
pkgrel=1
pkgdesc='Python Decorator module'
arch=('any')
url='http://pypi.python.org/pypi/decorator'
license=('BSD')
depends=('python2')
source=("http://pypi.python.org/packages/source/d/decorator/decorator-${pkgver}.tar.gz"
        'LICENSE.txt')
md5sums=('a8fc62acd705f487a71bc406e19e0cc6'
         '0ca76d2c707f09dbb04acc425ea1a08b')

build() {
  cd decorator-${pkgver}

  python2 setup.py build
}

package() {
  cd decorator-${pkgver}

  python2 setup.py install --root=${pkgdir} --optimize=1

  install -D -m644 ${srcdir}/LICENSE.txt \
    ${pkgdir}/usr/share/licenses/${pkgname}/LICENSE
}
