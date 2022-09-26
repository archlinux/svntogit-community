# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>
# Contributor: Johannes Dewender  arch at JonnyJD dot net
# Contributor: Ivan Sichmann Freitas <ivansichfreitas@gmail.com>
# Contributor: Brice Maron <brice@bmaron.net>
# Contributor: Nuno Araujo <nuno.araujo at russo79.com>
# Contributor: Steven Allen <steven {at} stebalien {dot} com>

pkgname=python-keyring
_name=keyring
pkgver=23.9.3
pkgrel=1
pkgdesc='Store and access your passwords safely'
arch=('any')
url='https://github.com/jaraco/keyring'
license=('PSF' 'MIT')
depends=('python-jaraco.classes' 'python-jeepney' 'python-secretstorage')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm' 'python-wheel')
checkdepends=('python-pytest-flake8' 'python-pytest-runner' 'python-pytest-black' 'python-pytest-cov' 'python-pytest-mypy')
optdepends=('python-keyrings-alt: Alternative backends'
            'python-dbus: kwallet backend')
source=(https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz)
sha512sums=('288e3aa71fc52fe4c7d769ad07fd51d058d700b72170f727023793a9b61bec5ef4cd70ed5c511383940c20125c6e39335a11cba0f1b582b5f47a62a24a8a4233')
b2sums=('5cb7a105283f4be809311f4616b9e8dfb0ae3d68ccaccbe5db69944b6e24606d352bd52dfbc62ca39a54df0a2696a912971a3cc72e30af26a5a17e66a2644b75')

build() {
  cd $_name-$pkgver

  python -m build
}

check() {
  cd $_name-$pkgver

  python -m pytest
}

package() {
  cd $_name-$pkgver

  python -m installer -d "$pkgdir" dist/*.whl
  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE

  rm -rf "$pkgdir"/usr/lib/python3.10/site-packages/keyring/tests
}

# vim:set ts=2 sw=2 et:
