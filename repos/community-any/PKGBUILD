# Maintainer: Thomas Dziedzic < gostrc at gmail >
# Contributor: Pierre Chapuis <catwell at archlinux dot us>

_name=decorator
pkgname=('python-decorator' 'python2-decorator')
pkgver=4.4.1
pkgrel=1
pkgdesc='Python Decorator module'
arch=('any')
url='https://pypi.python.org/pypi/decorator'
license=('BSD')
makedepends=('python2' 'python' 'python-setuptools' 'python2-setuptools')
source=("https://pypi.python.org/packages/source/${_name:0:1}/${_name}/${_name}-${pkgver}.tar.gz"
        'LICENSE.txt')
sha512sums=('12378702246b212d5fe0153dc97cafdb2afd4779c51fd224385e3c3562e1a1e3439574aa7c37c8521fe5f86a5f0b4d4b3075e0407cc249f8fa4b341e1ebe06e0'
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
