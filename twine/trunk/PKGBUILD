# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Chris Warrick <aur@chriswarrick.com>

pkgname=twine
pkgver=3.4.0
pkgrel=1
pkgdesc='Collection of utilities for interacting with PyPI'
arch=('any')
url='https://pypi.python.org/pypi/twine'
license=('Apache')
depends=('python-pkginfo' 'python-readme-renderer' 'python-requests' 'python-requests-toolbelt'
         'python-packaging' 'python-importlib-metadata' 'python-tqdm' 'python-keyring'
         'python-rfc3986' 'python-colorama')
makedepends=('python-setuptools-scm')
checkdepends=('git' 'python-munch' 'python-jaraco.envs' 'python-portend' 'python-pretend'
              'python-pytest-cov' 'python-pytest-services' 'python-pytest-socket')
provides=('python-twine')
conflicts=('python-twine')
replaces=('python-twine')
source=("https://github.com/pypa/twine/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('6ce4757048fe7b5ada8a384fa185e80cee8412ef7f0561f55a5cbec39c0069522b57e403f148b9b55c55330a577873a5e9597ca0a6b0fb0cce6b377c8df07e4e')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

build() {
  cd twine-$pkgver
  python setup.py build
}

check() {
  cd twine-$pkgver
  python setup.py egg_info
  python -m pytest
}

package() {
  cd twine-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  ln -s twine "$pkgdir"/usr/bin/twine3
}
