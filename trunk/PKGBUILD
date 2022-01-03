# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Chris Warrick <aur@chriswarrick.com>

pkgname=twine
pkgver=3.5.0
pkgrel=1
pkgdesc='Collection of utilities for interacting with PyPI'
arch=('any')
url='https://pypi.python.org/pypi/twine'
license=('Apache')
depends=('python-pkginfo' 'python-readme-renderer' 'python-requests' 'python-requests-toolbelt'
         'python-packaging' 'python-importlib-metadata' 'python-tqdm' 'python-keyring'
         'python-rfc3986' 'python-colorama')
makedepends=('python-dephell' 'python-setuptools-scm')
checkdepends=('git' 'python-munch' 'python-jaraco.envs' 'python-portend' 'python-pretend'
              'python-pytest-cov' 'python-pytest-services' 'python-pytest-socket')
provides=('python-twine')
conflicts=('python-twine')
replaces=('python-twine')
source=("https://github.com/pypa/twine/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('37219c1078bb7209123aee79c2d2bd73390c8ce4ab2bf6b5493a54e4ccb9c714a6422ee4a782b3c19d3a5344c1431285c666230729f44615b7761c7a5aff07d6')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

prepare() {
  cd twine-$pkgver
  dephell deps convert --from pyproject.toml --to setup.py
}

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
