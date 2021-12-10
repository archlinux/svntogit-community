# Maintainer: Thomas Dziedzic < gostrc at gmail >
# Contributor: Pierre Chapuis <catwell at archlinux dot us>

_name=decorator
pkgname=python-decorator
pkgver=5.1.0
pkgrel=3
pkgdesc='Python Decorator module'
arch=('any')
url='https://pypi.python.org/pypi/decorator'
license=('BSD')
depends=('python')
makedepends=('python' 'python-setuptools')
source=("https://pypi.python.org/packages/source/${_name:0:1}/${_name}/${_name}-${pkgver}.tar.gz"
        'LICENSE.txt')
sha512sums=('4acc0967af79f61c56adea3084c4e9f9de1c34fcbc7906db4bb1b0759e07ffed6eff0e4b21645dda5f37e96662742621f3d043e8c06a401841c7199a915afe18'
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
