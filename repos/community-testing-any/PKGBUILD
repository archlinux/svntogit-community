# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pygithub
pkgver=1.57
pkgrel=2
pkgdesc="Use the full Github API v3"
arch=('any')
license=('LGPL')
url="https://github.com/PyGithub/PyGithub"
depends=('python-deprecated' 'python-pyjwt' 'python-requests' 'python-pynacl')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-cryptography' 'python-httpretty' 'python-parameterized')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PyGithub/PyGithub/archive/v$pkgver.tar.gz")
sha512sums=('6c8880d21c5134581be6bc5549184c3f13cef8f360a46a459234f22f3dd4fc5f8b573cc3a5d870bba6c6129ff7b670e739d87e42f2e34ddcdf357a3fe2b3cadc')

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
