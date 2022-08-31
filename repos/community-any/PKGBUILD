# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Chris Warrick <aur@chriswarrick.com>

pkgname=twine
pkgver=3.7.0
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
source=("https://github.com/pypa/twine/archive/$pkgver/$pkgname-$pkgver.tar.gz"
        $pkgname-update-sampleproject.patch::https://github.com/pypa/twine/pull/885.patch)
sha512sums=('d7ddfdfcbaa7a5e3eba3657a06da090eeecbf373646e64d659f420fae4ba10c16c2c02e85bdf9c1f050b86177f19c85aa20183ad9d546cb053a11d60db0851f3'
            '6fe0126a79e1a681d9308ff7fd35b15a7e1e50437d634c7119d6b96aa3487b02b78cd575878673572276d630771014f1df5c63910715371c671b139addad8f73')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

prepare() {
  cd twine-$pkgver
  patch -p1 -i ../$pkgname-update-sampleproject.patch
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
