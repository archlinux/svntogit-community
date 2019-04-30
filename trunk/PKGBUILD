# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pygithub
pkgver=1.43.7
pkgrel=1
pkgdesc="Use the full Github API v3"
arch=('any')
license=('LGPL')
url="https://github.com/PyGithub/PyGithub"
depends=('python-pyjwt' 'python-requests' 'python-deprecated')
makedepends=('python-setuptools')
checkdepends=('python-cryptography' 'python-httpretty')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PyGithub/PyGithub/archive/v$pkgver.tar.gz")
sha512sums=('15d7c7ca6a505a259fe59c96db667a278179df7acfe794116f118bb18966c573cbdcd9276fe50b321fd759988810250a0268c2e8e330c1ef5a8bdcc3a50b6391')

build() {
  cd PyGithub-$pkgver
  python setup.py build
}

check() {
  cd PyGithub-$pkgver
  python -m lib2to3 -w -n tests
  python setup.py test
}

package() {
  cd PyGithub-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}
