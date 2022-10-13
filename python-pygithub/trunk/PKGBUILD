# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pygithub
pkgver=1.56
pkgrel=1
pkgdesc="Use the full Github API v3"
arch=('any')
license=('LGPL')
url="https://github.com/PyGithub/PyGithub"
depends=('python-deprecated' 'python-pyjwt' 'python-requests' 'python-pynacl')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-cryptography' 'python-httpretty' 'python-parameterized')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PyGithub/PyGithub/archive/v$pkgver.tar.gz")
sha512sums=('fe20d5eaa0f0267c49141fdd4d37bff81fe766a7db48662ceabc5a3f69ae7587bba6958d959a67dd224d4402f9b5785b67b461cac4c2f1bf5a15e8fcf8ae98ec')

build() {
  cd PyGithub-$pkgver
  python setup.py build
}

check() {
  cd PyGithub-$pkgver
  python -m pytest
}

package() {
  cd PyGithub-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}
