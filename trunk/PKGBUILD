# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>
# Contributor: Johannes Dewender  arch at JonnyJD dot net
# Contributor: Ivan Sichmann Freitas <ivansichfreitas@gmail.com>
# Contributor: Brice Maron <brice@bmaron.net>
# Contributor: Nuno Araujo <nuno.araujo at russo79.com>
# Contributor: Steven Allen <steven {at} stebalien {dot} com>

pkgname=python-keyring
_pkgname=keyring
pkgver=23.0.1
pkgrel=1
pkgdesc='Store and access your passwords safely'
arch=('any')
url='https://github.com/jaraco/keyring'
license=('PSF' 'MIT')
depends=('python-entrypoints' 'python-secretstorage' 'python-importlib-metadata')
makedepends=('git' 'python-setuptools-scm')
checkdepends=('python-pytest-flake8' 'python-pytest-runner' 'python-pytest-black' 'python-pytest-cov' 'python-pytest-mypy' 'python-keyrings-alt')
optdepends=('python-keyrings-alt: Alternative backends'
            'python-dbus: kwallet backend')
source=("git+$url#tag=v$pkgver")
sha512sums=('SKIP')

build() {
  cd $_pkgname

  python setup.py build
}

check() {
  cd $_pkgname

  python setup.py pytest
}

package() {
  cd $_pkgname

  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE

  rm -rf "$pkgdir"/usr/lib/python3.9/site-packages/keyring/tests
}

# vim:set ts=2 sw=2 et:
