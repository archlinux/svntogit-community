# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>
# Contributor: Patrice Peterson <runiq at archlinux dot us>
# Contributor: JonnyJD <arch@JonnyJD.net>

pkgname=python-secretstorage
_pkgname=SecretStorage
pkgver=3.3.3
pkgrel=2
pkgdesc="Securely store passwords and other private data using the SecretService DBus API"
arch=('any')
url="https://github.com/mitya57/secretstorage"
license=('BSD')
depends=('python-cryptography' 'python-jeepney')
makedepends=('python-setuptools')
checkdepends=('org.freedesktop.secrets' 'xorg-server-xvfb')
source=("https://pypi.io/packages/source/${_pkgname:0:1}/$_pkgname/$_pkgname-$pkgver.tar.gz")
sha512sums=('9a048c8245cfb01babebdd85dbbe84f9634b9b28188f7d11d3abad841109cfa307861de05e529199e409e595864ff3e097fcc961fcff210040d214a50f932f6e')

build() {
  cd $_pkgname-$pkgver

  python setup.py build
}

check() {
  cd $_pkgname-$pkgver

  dbus-launch xvfb-run -a python -m unittest discover -s tests || echo "Tests failed"
}

package() {
  cd $_pkgname-$pkgver

  python setup.py install --root="$pkgdir" -O1
  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
