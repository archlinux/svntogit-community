# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Chris Warrick <aur@chriswarrick.com>

pkgname=twine
pkgver=1.15.0
pkgrel=1
pkgdesc='Collection of utilities for interacting with PyPI'
arch=('any')
url='https://pypi.python.org/pypi/twine'
license=('Apache')
depends=('python-setuptools' 'python-requests-toolbelt' 'python-pkginfo' 'python-tqdm'
         'python-readme-renderer')
provides=('python-twine')
conflicts=('python-twine')
replaces=('python-twine')
checkdepends=('python-pytest-runner' 'python-pretend')
source=("$pkgname-$pkgver.tar.gz::https://github.com/pypa/twine/archive/$pkgver.tar.gz")
sha512sums=('e0eae05c108e1e766a0a8ec684e3423b0537c8aa671675f30403171fd4f48ec65666d407df53f6dd9eefa0b98e5fd2fdf7dbf1f0f9150686c499de131f6f2435')

build() {
  cd twine-$pkgver
  python setup.py build
}

check() {
  cd twine-$pkgver
  python setup.py pytest
}

package() {
  cd twine-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  ln -s twine "$pkgdir"/usr/bin/twine3
}
