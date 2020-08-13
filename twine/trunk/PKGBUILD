# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Chris Warrick <aur@chriswarrick.com>

pkgname=twine
pkgver=3.0.0
pkgrel=1
pkgdesc='Collection of utilities for interacting with PyPI'
arch=('any')
url='https://pypi.python.org/pypi/twine'
license=('Apache')
depends=('python-pkginfo' 'python-readme-renderer' 'python-requests' 'python-requests-toolbelt'
         'python-setuptools' 'python-tqdm' 'python-keyring')
makedepends=('python-setuptools-scm')
checkdepends=('git' 'python-munch' 'python-jaraco.envs' 'python-portend' 'python-pretend'
              'python-pytest-services')
provides=('python-twine')
conflicts=('python-twine')
replaces=('python-twine')
source=("$pkgname-$pkgver.tar.gz::https://github.com/pypa/twine/archive/$pkgver.tar.gz")
sha512sums=('1f5577c74c47618ae07672b53633110a5ecb486d25046cb87f36cbf5974b679714f962803b9dc6e970c57d8f2542b323e11437e76effe7172511557b56df5f12')

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
