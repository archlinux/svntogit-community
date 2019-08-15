# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Timothée Ravier <tim@siosm.fr>

_commit=58a7ef6ce1c4c5824aa873932c67c858d1030771
_name=dulwich
pkgname=python-dulwich
pkgver=0.19.12.r3.g29fc0ac
pkgrel=1
pkgdesc='Pure-Python implementation of the Git file formats and protocols'
arch=('x86_64')
url=https://www.dulwich.io
license=('GPL')
depends=('python-certifi' 'python-urllib3')
checkdepends=('python-mock')
source=("https://github.com/dulwich/dulwich/archive/$_commit.tar.gz")
sha512sums=('fef54738d2e6b76ad2d4da5b8f638a5e60b9fc66f47f7ca1e124a6dc3cc380114434c1586bfd24e8f56efa74f7abcaaaeecaf713cff8e38d6e3f82c24836e0b5')

build() {
  cd $_name-$_commit
  python setup.py build
}

check() {
  cd $_name-$_commit
  python -m unittest dulwich.tests.test_suite
}

package() {
  cd $_name-$_commit
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
}

# vim:set ts=2 sw=2 et:
