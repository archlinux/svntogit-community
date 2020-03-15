# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pygithub
pkgver=1.47
pkgrel=1
pkgdesc="Use the full Github API v3"
arch=('any')
license=('LGPL')
url="https://github.com/PyGithub/PyGithub"
depends=('python-deprecated' 'python-pyjwt' 'python-requests')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-cryptography' 'python-httpretty' 'python-parameterized')
source=("$pkgname-$pkgver.tar.gz::https://github.com/PyGithub/PyGithub/archive/v$pkgver.tar.gz")
sha512sums=('2c5804f86e1b3c47eb276dc9256983e3b7b36494e156263cf49b4d2d1e9579194f6d5ed17a7f2a8e9a4eab3824f6c7e8595960b98115feff5acb08bed03d86e3')

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
