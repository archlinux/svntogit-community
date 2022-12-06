# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Chris Warrick <aur@chriswarrick.com>

pkgname=twine
pkgver=4.0.2
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
sha512sums=('94dec0b08ea8f4cc5900d743b750f02a668c738d402632a80faef24220f87b4b14824966d6d902e9ddaab741e4091d6a370a7660d02ca27fd6fd0d251a473ab5')


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
  # Ignored tests are copied from upstream tox.ini:
  # https://github.com/pypa/twine/blob/4.0.2/tox.ini#L16
  SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver python -m pytest --ignore-glob '*integration*.py'
}

package() {
  cd $pkgname-$pkgver

  python -m installer -d "$pkgdir" dist/*.whl

  ln -s twine "$pkgdir"/usr/bin/twine3
}
