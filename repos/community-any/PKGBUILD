# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Chris Warrick <aur@chriswarrick.com>

pkgbase=twine
pkgname=('twine' 'python2-twine')
pkgver=1.13.0
pkgrel=1
pkgdesc='Collection of utilities for interacting with PyPI'
arch=('any')
url='https://pypi.python.org/pypi/twine'
license=('Apache')
makedepends=('python-setuptools' 'python2-setuptools' 'python-requests-toolbelt'
             'python2-requests-toolbelt' 'python-pkginfo' 'python2-pkginfo' 'python-tqdm'
             'python2-tqdm' 'python-readme-renderer' 'python2-readme-renderer' 'python2-pyblake2')
checkdepends=('python-pytest-runner' 'python2-pytest-runner' 'python-pretend' 'python2-pretend')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/pypa/twine/archive/$pkgver.tar.gz")
sha512sums=('c72c6a3e12e78712335fdcc7917b7edd69ca34829a649f6e37501ee813501dc0bff0d2eda2bf5e4e30f32daef8fe67aed79679ad327b93f01ccf646e3881883c')

prepare() {
  cp -a twine-$pkgver{,-py2}
}

build() {
  cd "$srcdir"/twine-$pkgver
  python setup.py build

  cd "$srcdir"/twine-$pkgver-py2
  python2 setup.py build
}

check() {
  cd "$srcdir"/twine-$pkgver
  python setup.py pytest

  cd "$srcdir"/twine-$pkgver-py2
  python2 setup.py pytest
}

package_twine() {
  depends=('python-setuptools' 'python-requests-toolbelt' 'python-pkginfo' 'python-tqdm'
           'python-readme-renderer')
  provides=('python-twine')
  conflicts=('python-twine')
  replaces=('python-twine')

  cd twine-$pkgver
  python3 setup.py install --root="$pkgdir" --optimize=1
  ln -s twine "$pkgdir"/usr/bin/twine3
}

package_python2-twine() {
  depends=('python2-setuptools' 'python2-requests-toolbelt' 'python2-pkginfo' 'python2-tqdm'
           'python2-readme-renderer' 'python2-pyblake2')

  cd twine-$pkgver-py2
  python2 setup.py install --root="$pkgdir" --optimize=1
  mv "$pkgdir"/usr/bin/twine{,2}
}

# vim:set ts=2 sw=2 et:
