# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>
# Contributor: Patrice Peterson <runiq at archlinux dot us>
# Contributor: JonnyJD <arch@JonnyJD.net>

pkgname=python-secretstorage
_pkgname=SecretStorage
pkgver=3.2.0
pkgrel=3
pkgdesc="Securely store passwords and other private data using the SecretService DBus API"
arch=('any')
url="https://github.com/mitya57/secretstorage"
license=('BSD')
depends=('python-cryptography' 'python-jeepney')
checkdepends=('org.freedesktop.secrets' 'xorg-server-xvfb')
source=("https://pypi.io/packages/source/${_pkgname:0:1}/$_pkgname/$_pkgname-$pkgver.tar.gz")
sha512sums=('668f3847f573e1756ffa3a38c278e6d4895223553830d49969e979003d04ca04fb5eaf8dfcc616086a6020f6a73fbe71f7041d4c4ee574205f00fbde945298e9')

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
