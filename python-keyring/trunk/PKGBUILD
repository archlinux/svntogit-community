# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>
# Contributor: Johannes Dewender  arch at JonnyJD dot net
# Contributor: Ivan Sichmann Freitas <ivansichfreitas@gmail.com>
# Contributor: Brice Maron <brice@bmaron.net>
# Contributor: Nuno Araujo <nuno.araujo at russo79.com>
# Contributor: Steven Allen <steven {at} stebalien {dot} com>

pkgname=python-keyring
_pkgname=keyring
pkgver=21.0.0
pkgrel=1
pkgdesc='Store and access your passwords safely'
arch=('any')
url='https://github.com/jaraco/keyring'
license=('PSF' 'MIT')
depends=('python-entrypoints' 'python-secretstorage')
makedepends=('python-setuptools-scm' 'python-entrypoints')
checkdepends=('python-pytest-flake8' 'python-pytest-runner' 'python-pytest-black' 'python-pytest-cov' 'python-keyrings-alt')
optdepends=('python-keyrings-alt: Alternative backends'
            'python-dbus: kwallet backend')
source=("https://pypi.io/packages/source/${_pkgname:0:1}/$_pkgname/$_pkgname-$pkgver.tar.gz")
sha512sums=('0ea67db52c1dd62c4c186ea49fa7939ee54d216da33c0fdd9823079357dc79e9a619928cf21e120732551a50287574d03bc921b72bd32123cc5410f05701ef18')

prepare() {
  cd $_pkgname-$pkgver

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

  rm -rf "$pkgdir"/usr/lib/python3.8/site-packages/keyring/tests
}

# vim:set ts=2 sw=2 et:
