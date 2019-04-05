# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pygithub
pkgver=1.43.6
pkgrel=1
pkgdesc="Use the full Github API v3"
arch=('any')
license=('LGPL')
url="https://github.com/PyGithub/PyGithub"
depends=('python-pyjwt' 'python-requests' 'python-deprecated')
makedepends=('python-setuptools')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PyGithub/PyGithub/archive/v$pkgver.tar.gz")
sha512sums=('bb1bc7f21286bcdb49a0450ab1246e2813b983acd0b4209ff8dd8692d3b36ca208e5e45edfebe1002f54019d558310d33838ed89d229f8bea5c642414f118f41')

build() {
  cd PyGithub-$pkgver
  python setup.py build
}

check() {
  cd PyGithub-$pkgver
  python setup.py test
}

package() {
  cd PyGithub-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}
