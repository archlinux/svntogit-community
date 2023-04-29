# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Chris Warrick <aur@chriswarrick.com>

pkgname=twine
pkgver=4.0.2
_commit=75c3d8623c0847d8ce5a59c1d14a9fcc71e2a4a2
pkgrel=4
pkgdesc='Collection of utilities for interacting with PyPI'
arch=('any')
url='https://github.com/pypa/twine/'
license=('Apache')
depends=('python-pkginfo' 'python-readme-renderer' 'python-requests' 'python-requests-toolbelt'
         'python-urllib3' 'python-importlib-metadata' 'python-keyring' 'python-rfc3986'
         'python-rich')
makedepends=('git' 'python-build' 'python-installer' 'python-setuptools-scm' 'python-wheel')
checkdepends=('git' 'python-munch' 'python-jaraco.envs' 'python-portend' 'python-pretend' 'python-tox'
              'python-pytest-cov' 'python-pytest-services' 'python-pytest-socket')
provides=('python-twine')
conflicts=('python-twine')
replaces=('python-twine')
source=("git+https://github.com/pypa/twine.git#commit=$_commit")
sha512sums=('SKIP')

build() {
  cd $pkgname
  python -m build -nw
}

check() {
  cd $pkgname
  # Ignored tests are copied from upstream tox.ini:
  # https://github.com/pypa/twine/blob/4.0.2/tox.ini#L16
  python -m pytest --ignore-glob '*integration*.py'
}

package() {
  cd $pkgname
  python -m installer -d "$pkgdir" dist/*.whl
  ln -s twine "$pkgdir"/usr/bin/twine3
}
