# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-betamax-matchers
pkgver=0.4.0
pkgrel=9
pkgdesc="Experimental set of Matchers for Betamax that may possibly end up in the main package"
arch=('any')
license=('GPL')
url='https://github.com/sigmavirus24/betamax_matchers'
depends=('python-requests-toolbelt' 'python-betamax')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner')
source=("$pkgname-$pkgver.tar.gz::https://github.com/sigmavirus24/betamax_matchers/archive/$pkgver.tar.gz")
sha512sums=('202255d9895b118d03efa20aa64f5b099045750dcb9a1ad3eda164d3da372207f1bee8a40f63cdf179da90cfc4380e5a004e5f9c94f006a6f3dbc64e29766c86')

check() {
  cd betamax_matchers-$pkgver
  python setup.py pytest
}

package() {
  cd betamax_matchers-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -D -m644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
