# Maintainer: Thomas Dziedzic < gostrc at gmail >
# Contributor: Pierre Chapuis <catwell at archlinux dot us>

_name=decorator
pkgname=python-decorator
pkgver=4.4.2
pkgrel=4
pkgdesc='Python Decorator module'
arch=('any')
url='https://pypi.python.org/pypi/decorator'
license=('BSD')
depends=('python')
makedepends=('python' 'python-setuptools')
source=("https://pypi.python.org/packages/source/${_name:0:1}/${_name}/${_name}-${pkgver}.tar.gz"
        'LICENSE.txt')
sha512sums=('c068efd4e70764ac447b772c9c29625c2180dad256b2b4e46a50a8479fc1d7de09b114c2ba11bb37dd58774ed9460d2e0ea9fa76061833a2d3c2676ac91a0db1'
            '0a06dfb3f470b8d3b056bd4e4776df715876d04d0acc86dec536fa7cff0214ba5255833923558d1778db730d080960f31d5e12f939e761530823b6e70646b5c2')

build() {
  cd "$srcdir/$_name-$pkgver"

  python3 setup.py build
}

package() {
  cd "${srcdir}/${_name}-${pkgver}"

  python3 setup.py install --root="${pkgdir}" --optimize=1

  install -D -m644 "${srcdir}/LICENSE.txt" \
    "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}

check() {
  cd "$srcdir/${_name}-$pkgver"

  python3 setup.py test
}
