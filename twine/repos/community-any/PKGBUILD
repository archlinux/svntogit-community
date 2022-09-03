# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Chris Warrick <aur@chriswarrick.com>

pkgname=twine
pkgver=4.0.1
pkgrel=1
pkgdesc='Collection of utilities for interacting with PyPI'
arch=('any')
url='https://github.com/pypa/twine/'
license=('Apache')
depends=('python-pkginfo' 'python-readme-renderer' 'python-requests' 'python-requests-toolbelt'
         'python-packaging' 'python-importlib-metadata' 'python-tqdm' 'python-keyring'
         'python-rfc3986' 'python-colorama')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm' 'python-wheel')
checkdepends=('git' 'python-munch' 'python-jaraco.envs' 'python-portend' 'python-pretend' 'python-tox'
              'python-pytest-cov' 'python-pytest-services' 'python-pytest-socket' 'python-rich')
provides=('python-twine')
conflicts=('python-twine')
replaces=('python-twine')
source=("$url/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('0b5d24c56731239400b6713e0e52d1cfdb399a84e886b02ea4b59e7af69cc1578e03bf442cca4b2ea5f400995955d27c8d9d3cc17a6ea59013bdaaf6ac63a567')


prepare() {
  cd $pkgname-$pkgver

  # This is needed because twine uses setuptools-scm's file finder hook to include package data,
  # but the git checkout we use don't contain the needed SCM info.
  # dephell generates a pattern for this automatically.
  echo "recursive-include twine *.typed" > MANIFEST.in
}

build() {
  cd $pkgname-$pkgver

  SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver python -m build -nw
}

check() {
  cd $pkgname-$pkgver

  SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver python -m pytest
}

package() {
  cd $pkgname-$pkgver

  python -m installer -d "$pkgdir" dist/*.whl

  ln -s twine "$pkgdir"/usr/bin/twine3
}
