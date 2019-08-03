# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>
# Contributor: Johannes Dewender  arch at JonnyJD dot net
# Contributor: Ivan Sichmann Freitas <ivansichfreitas@gmail.com>
# Contributor: Brice Maron <brice@bmaron.net>
# Contributor: Nuno Araujo <nuno.araujo at russo79.com>
# Contributor: Steven Allen <steven {at} stebalien {dot} com>

pkgname=python-keyring
_pkgname=keyring
pkgver=19.0.2
pkgrel=1
pkgdesc='Store and access your passwords safely'
arch=('any')
url='https://github.com/jaraco/keyring'
license=('PSF' 'MIT')
depends=('python-entrypoints' 'python-secretstorage')
makedepends=('python-setuptools-scm' 'python-entrypoints')
checkdepends=('python-pytest-flake8' 'python-pytest-runner' 'python-pytest-black')
optdepends=('python-keyrings-alt: Alternative backends'
            'python-dbus: kwallet backend')
source=("https://pypi.io/packages/source/${_pkgname:0:1}/$_pkgname/$_pkgname-$pkgver.tar.gz")
sha512sums=('985d69101f673cda04c0a9ee07a62a92d07ee38b7dcc3f4c85fedaa7c38e52da7609d5fc53d445e2c75314be3893b86283b6b5f7b2f8046edc36b782d8675142')

build() {
  cd $_pkgname-$pkgver

  python setup.py build
}

check() {
  cd $_pkgname-$pkgver

  python setup.py pytest
}

package() {
  cd $_pkgname-$pkgver

  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et:
