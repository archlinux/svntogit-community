# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>
# Contributor: Patrice Peterson <runiq at archlinux dot us>
# Contributor: JonnyJD <arch@JonnyJD.net>

pkgname=python-secretstorage
_pkgname=SecretStorage
pkgver=3.1.1
pkgrel=1
pkgdesc="Securely store passwords and other private data using the SecretService DBus API"
arch=('any')
url="https://github.com/mitya57/secretstorage"
license=('BSD')
depends=('python-cryptography' 'python-jeepney')
checkdepends=('gnome-keyring' 'xorg-server-xvfb')
source=("https://pypi.io/packages/source/${_pkgname:0:1}/$_pkgname/$_pkgname-$pkgver.tar.gz")
sha512sums=('295e0f75c772edf153480730dc20051f06e60e040a18f169620cb4aaa37b8c1a254a496464d3794a38cf49fa884a7b561fe364816f0d12a5b2622c77259f03cf')

build() {
  cd $_pkgname-$pkgver

  python setup.py build
}

check() {
  cd $_pkgname-$pkgver

  dbus-launch xvfb-run -a python -m unittest discover -s tests || warning "Tests failed"
}

package() {
  cd $_pkgname-$pkgver

  python setup.py install --root="$pkgdir" -O1
  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
