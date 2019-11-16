# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Chris Warrick <aur@chriswarrick.com>

pkgname=twine
pkgver=2.0.0
pkgrel=1
pkgdesc='Collection of utilities for interacting with PyPI'
arch=('any')
url='https://pypi.python.org/pypi/twine'
license=('Apache')
depends=('python-setuptools' 'python-requests-toolbelt' 'python-pkginfo' 'python-tqdm'
         'python-readme-renderer' 'python-keyring')
makedepends=('python-setuptools-scm')
provides=('python-twine')
conflicts=('python-twine')
replaces=('python-twine')
checkdepends=('python-pytest-runner' 'python-pretend')
source=("$pkgname-$pkgver.tar.gz::https://github.com/pypa/twine/archive/$pkgver.tar.gz")
sha512sums=('a13d1f3fb547f41356d222befdfa0aa293876844c872222c68d0e6acaa1f97e2f6be9ea0c7815ac054bb826b61679692fa6e9f8eb861c70a1c87b4ede4442f2b')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

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
