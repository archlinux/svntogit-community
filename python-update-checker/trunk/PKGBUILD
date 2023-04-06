# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-update-checker
pkgver=0.18.0
pkgrel=6
pkgdesc="A python module that will check for package updates"
arch=('any')
license=('BSD')
url='https://github.com/bboe/update_checker'
depends=('python-requests')
provides=('python-update_checker')
conflicts=('python-update_checker')
replaces=('python-update_checker')
makedepends=('python-setuptools' 'python-requests')
checkdepends=('python-pytest')
source=("https://pypi.io/packages/source/u/update_checker/update_checker-$pkgver.tar.gz")
sha512sums=('ab77b4904f27fc3a4f382dda08cf86fceedc6fa1c6a1f2b1d6ea42688f95ea1fbef4168d69233aec4a489d9ff7f93af60e8f1bf62854aa4d2f54136c540d26f1')

build() {
  cd update_checker-$pkgver
  python setup.py build
}

check() {
  cd update_checker-$pkgver
  pytest
}

package() {
  cd update_checker-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -D -m644 LICENSE.txt "$pkgdir"/usr/share/licenses/$pkgname/LICENSE.txt
}
