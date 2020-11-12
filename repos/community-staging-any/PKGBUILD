# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Chris Warrick <aur@chriswarrick.com>

pkgname=twine
pkgver=3.2.0
pkgrel=2
pkgdesc='Collection of utilities for interacting with PyPI'
arch=('any')
url='https://pypi.python.org/pypi/twine'
license=('Apache')
depends=('python-pkginfo' 'python-readme-renderer' 'python-requests' 'python-requests-toolbelt'
         'python-setuptools' 'python-tqdm' 'python-keyring' 'python-rfc3986' 'python-colorama')
makedepends=('python-setuptools-scm')
checkdepends=('git' 'python-munch' 'python-jaraco.envs' 'python-portend' 'python-pretend'
              'python-pytest-cov' 'python-pytest-services')
provides=('python-twine')
conflicts=('python-twine')
replaces=('python-twine')
source=("$pkgname-$pkgver.tar.gz::https://github.com/pypa/twine/archive/$pkgver.tar.gz")
sha512sums=('9959430913ea570d22f2d8b94e929af36b409b71691b3f66de8ddb77cfbfbe36590e21a6062db2a4a4f56ce2eb96984b0a474a93ea96b7734f53ada7a6411c28')

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
