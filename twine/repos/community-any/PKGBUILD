# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Chris Warrick <aur@chriswarrick.com>

pkgname=twine
pkgver=1.14.0
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
sha512sums=('4044332727a1a6bb0ffd38d83ddd3a04ad96e013d3894dee3c468527cb8fa9c5d86161bfdcbe357ebf8440d46776b3688131d57ed06cac13cb0893a64861b99a')

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
