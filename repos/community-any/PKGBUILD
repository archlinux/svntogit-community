# Maintainer: Thomas Dziedzic < gostrc at gmail >
# Contributor: Pierre Chapuis <catwell at archlinux dot us>

_name=decorator
pkgname=python-decorator
pkgver=5.0.7
pkgrel=1
pkgdesc='Python Decorator module'
arch=('any')
url='https://pypi.python.org/pypi/decorator'
license=('BSD')
depends=('python')
makedepends=('python' 'python-setuptools')
source=("https://pypi.python.org/packages/source/${_name:0:1}/${_name}/${_name}-${pkgver}.tar.gz"
        'LICENSE.txt')
sha512sums=('78ae542b2f20d3d1714cf13120b14db308d73b866591c8ae42d69103a11e8d05a553438619bb68730310857587746e9d211ec4cf4b3fb5fbbcef030183b65294'
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
