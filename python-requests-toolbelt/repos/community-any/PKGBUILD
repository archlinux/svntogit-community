# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: eolianoe <eolianoe At GoogleMAIL DoT com>

pkgbase=python-requests-toolbelt
pkgname=('python-requests-toolbelt' 'python2-requests-toolbelt')
pkgver=0.9.1
pkgrel=1
pkgdesc="A toolbelt of useful classes and functions to be used with python-requests."
arch=('any')
url="https://github.com/requests/toolbelt"
license=('Apache')
makedepends=('python-setuptools' 'python2-setuptools' 'python-requests' 'python2-requests')
checkdepends=('python-pytest' 'python2-pytest' 'python-betamax' 'python2-betamax'
              'python-mock' 'python2-mock' 'python-pyopenssl' 'python2-pyopenssl')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/requests/toolbelt/archive/$pkgver.tar.gz")
sha512sums=('12667056c225ce0bc88a5959660103feed23810890abd3890ef15581aa64c09c0552c3974473e1742cbe6200bd37d6475ad34ec051e83d4fbf0a33f320dbc0cc')

prepare() {
  cp -a toolbelt-$pkgver{,-py2}
}

build() {
  cd "$srcdir"/toolbelt-$pkgver
  python setup.py build

  cd "$srcdir"/toolbelt-$pkgver-py2
  python2 setup.py build
}

check() {
  cd "$srcdir"/toolbelt-$pkgver
  py.test

  cd "$srcdir"/toolbelt-$pkgver-py2
  py.test2
}

package_python-requests-toolbelt() {
  depends=('python-requests')

  cd toolbelt-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}

package_python2-requests-toolbelt() {
  depends=('python2-requests')

  cd toolbelt-$pkgver-py2
  python2 setup.py install --root="$pkgdir" --optimize=1
}
