# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pygithub
pkgver=1.43.5
pkgrel=2
pkgdesc="Use the full Github API v3"
arch=('any')
license=('LGPL')
url="https://github.com/PyGithub/PyGithub"
depends=('python-pyjwt' 'python-requests' 'python-deprecated')
makedepends=('python-setuptools')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PyGithub/PyGithub/archive/v$pkgver.tar.gz")
sha512sums=('703de65539c1e2af4462285d1788611d98a4052fcf223b54795da34679d1e327de8758d895d73b707f87f8a006171bc5c6b8182388ac6fde3808be8af6021dde')

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
