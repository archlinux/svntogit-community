# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pygithub
pkgver=1.44
pkgrel=1
pkgdesc="Use the full Github API v3"
arch=('any')
license=('LGPL')
url="https://github.com/PyGithub/PyGithub"
depends=('python-pyjwt' 'python-requests' 'python-deprecated')
makedepends=('python-setuptools')
checkdepends=('python-cryptography' 'python-httpretty')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PyGithub/PyGithub/archive/v$pkgver.tar.gz")
sha512sums=('26aa86822fb8c3ca8a8a0e8d5cd9bf9457cab8a4aa006fa195bb4922867627b5516adbee19cbf5c30d24de8266b496741ae7f4dd8c7cc0494044e6cd585402b1')

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
