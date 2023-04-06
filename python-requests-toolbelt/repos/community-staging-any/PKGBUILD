# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: eolianoe <eolianoe At GoogleMAIL DoT com>

pkgname=python-requests-toolbelt
pkgver=0.10.1
pkgrel=2
pkgdesc="A toolbelt of useful classes and functions to be used with python-requests."
arch=('any')
url="https://github.com/requests/toolbelt"
license=('Apache')
depends=('python-requests')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-betamax' 'python-ndg-httpsclient' 'python-pyopenssl'
              'python-trustme')
source=("$pkgname-$pkgver.tar.gz::https://github.com/requests/toolbelt/archive/$pkgver.tar.gz")
sha512sums=('ad6dfe3329c8be5a4521d223d25ec303201e706b34199c084efd0a30b8bc8cfb3382e80a502dc25bd5f7e5b2774a119d2255c49408979aaec45e221f412a7b52')

build() {
  cd toolbelt-$pkgver
  python setup.py build
}

check() {
  cd toolbelt-$pkgver
  pytest
}

package() {
  cd toolbelt-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}
