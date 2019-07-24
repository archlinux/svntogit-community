# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pygithub
pkgver=1.43.8
pkgrel=1
pkgdesc="Use the full Github API v3"
arch=('any')
license=('LGPL')
url="https://github.com/PyGithub/PyGithub"
depends=('python-pyjwt' 'python-requests' 'python-deprecated')
makedepends=('python-setuptools')
checkdepends=('python-cryptography' 'python-httpretty')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PyGithub/PyGithub/archive/v$pkgver.tar.gz")
sha512sums=('dc58166ebb27f855ed4f32448029abe7e53b8050d8d99029d460f2dd94180ca8bcef68a75469293abd021f70cc3c67c32061e6439db1b3f1dc77af464c658bb6')

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
