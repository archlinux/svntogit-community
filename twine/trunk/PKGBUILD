# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Chris Warrick <aur@chriswarrick.com>

pkgname=twine
pkgver=3.4.2
pkgrel=2
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
sha512sums=('3f6d8992294a35e2a26be64f56c88d31af63b05f3f477d545bc82d928ca1b9939d23fa489eca5232502a49def77d489eaf6a29663d150f78b5cdb99749ff9b50')

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
