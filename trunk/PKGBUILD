# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Chris Warrick <aur@chriswarrick.com>

pkgname=twine
pkgver=3.6.0
pkgrel=1
pkgdesc='Collection of utilities for interacting with PyPI'
arch=('any')
url='https://pypi.python.org/pypi/twine'
license=('Apache')
depends=('python-pkginfo' 'python-readme-renderer' 'python-requests' 'python-requests-toolbelt'
         'python-packaging' 'python-importlib-metadata' 'python-tqdm' 'python-keyring'
         'python-rfc3986' 'python-colorama')
makedepends=('python-pyproject2setuppy' 'python-setuptools-scm')
checkdepends=('git' 'python-munch' 'python-jaraco.envs' 'python-portend' 'python-pretend'
              'python-pytest-cov' 'python-pytest-services' 'python-pytest-socket')
provides=('python-twine')
conflicts=('python-twine')
replaces=('python-twine')
source=("https://github.com/pypa/twine/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('41da4d89ac69c692a98545aefffd9afd4c7b0287179807906504b4121bf9257095b227ec2966d98983939fa76fb8509f6ffa2577c0e7b4c7f43f614f44745460')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

prepare() {
  cd twine-$pkgver
  # This is needed because twine uses setuptools-scm's file finder hook to include package data,
  # but the git checkout we use don't contain the needed SCM info.
  # dephell generates a pattern for this automatically.
  echo "recursive-include twine *.typed" > MANIFEST.in
}

build() {
  cd twine-$pkgver
  python -m pyproject2setuppy build
}

check() {
  cd twine-$pkgver
  python -m pyproject2setuppy egg_info
  python -m pytest
}

package() {
  cd twine-$pkgver
  python -m pyproject2setuppy install --root="$pkgdir" --optimize=1
  ln -s twine "$pkgdir"/usr/bin/twine3
}
