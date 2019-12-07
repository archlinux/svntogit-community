# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>
# Contributor: Johannes Dewender  arch at JonnyJD dot net
# Contributor: Ivan Sichmann Freitas <ivansichfreitas@gmail.com>
# Contributor: Brice Maron <brice@bmaron.net>
# Contributor: Nuno Araujo <nuno.araujo at russo79.com>
# Contributor: Steven Allen <steven {at} stebalien {dot} com>

pkgname=python-keyring
_pkgname=keyring
pkgver=19.3.0
pkgrel=1
pkgdesc='Store and access your passwords safely'
arch=('any')
url='https://github.com/jaraco/keyring'
license=('PSF' 'MIT')
depends=('python-entrypoints' 'python-secretstorage')
makedepends=('python-setuptools-scm' 'python-entrypoints')
checkdepends=('python-pytest-flake8' 'python-pytest-runner' 'python-pytest-black' 'python-keyrings-alt')
optdepends=('python-keyrings-alt: Alternative backends'
            'python-dbus: kwallet backend')
source=("https://pypi.io/packages/source/${_pkgname:0:1}/$_pkgname/$_pkgname-$pkgver.tar.gz")
sha512sums=('c0950a6c449718d735539014ed6d2b4455d615da6773d18d189c736260bd785437e34a2ae1b16ad42b36229996f5066cb3cd33083eeb8177f4ba886406c85d06')

prepare() {
  cd $_pkgname-$pkgver

  sed -i 's| --cov||' pytest.ini
  rm tests/test_packaging.py
}

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
