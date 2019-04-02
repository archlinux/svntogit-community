# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Chris Warrick <aur@chriswarrick.com>

pkgname=twine
pkgver=1.13.0
pkgrel=2
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
sha512sums=('c72c6a3e12e78712335fdcc7917b7edd69ca34829a649f6e37501ee813501dc0bff0d2eda2bf5e4e30f32daef8fe67aed79679ad327b93f01ccf646e3881883c')

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
