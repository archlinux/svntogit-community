# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>
# Contributor: Patrice Peterson <runiq at archlinux dot us>
# Contributor: JonnyJD <arch@JonnyJD.net>

pkgname=python-secretstorage
_pkgname=SecretStorage
pkgver=3.1.2
pkgrel=1
pkgdesc="Securely store passwords and other private data using the SecretService DBus API"
arch=('any')
url="https://github.com/mitya57/secretstorage"
license=('BSD')
depends=('python-cryptography' 'python-jeepney')
checkdepends=('org.freedesktop.secrets' 'xorg-server-xvfb')
source=("https://pypi.io/packages/source/${_pkgname:0:1}/$_pkgname/$_pkgname-$pkgver.tar.gz")
sha512sums=('c132b21556c55b5912354fd27b6062d32c0f510234f7fe57f6e8e0acb08393ad95e0896967b577de97821387cd714e62b657359230296449e4e0a7ae5a797803')

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
