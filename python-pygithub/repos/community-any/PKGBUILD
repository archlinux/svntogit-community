# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pygithub
pkgver=1.58.2
pkgrel=1
pkgdesc="Use the full Github API v3"
arch=('any')
license=('LGPL')
url="https://github.com/PyGithub/PyGithub"
depends=('python-deprecated' 'python-pyjwt' 'python-requests' 'python-pynacl')
makedepends=('python-setuptools-scm')
checkdepends=('python-pytest' 'python-cryptography' 'python-httpretty' 'python-parameterized')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PyGithub/PyGithub/archive/v$pkgver.tar.gz")
sha512sums=('00e9fb09bfc96971a55cbda62a89ad84aa7cfa0c1a98c74faebcbd46843f29b98f8635cef9737699438e1413c6286d4faf4444756677334330ebe4a71c9e74f2')

build() {
  cd PyGithub-$pkgver
  SETUPTOOLS_SCM_PRETEND_VERSION=${pkgver} \
  python setup.py build
}

check() {
  cd PyGithub-$pkgver
  python -m pytest
}

package() {
  cd PyGithub-$pkgver
  SETUPTOOLS_SCM_PRETEND_VERSION=${pkgver} \
  python setup.py install --root="$pkgdir" --optimize=1
}
