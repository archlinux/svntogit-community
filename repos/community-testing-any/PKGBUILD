# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Jim Bridgewater <jwbwater at gmail dot com>
# Contributor: delta48 <dark.magician.48[at]gmail[dot]com>

pkgname=python-pyperclip
pkgver=1.8.2
_commit=714be1f3f8e5bb289bbd77aa83be212d660f3cb0
pkgrel=5
pkgdesc="A cross-platform clipboard module for Python"
arch=('any')
url="https://github.com/asweigart/pyperclip"
license=('BSD')
makedepends=('python-setuptools')
# GTK/Qt tests crash xvfb, and Klipper tests require a running klipper
checkdepends=('xorg-server-xvfb' 'python-pytest' 'xsel' 'xclip')
depends=('python')
optdepends=('xclip: xclip backend'
            'xsel: xsel backend'
            'plasma-workspace: klipper backend')
source=("$pkgname-$_commit.tar.gz::https://github.com/asweigart/pyperclip/archive/$_commit.tar.gz")
sha512sums=('616619dbbfec3e28f4bc86ef9088df0b77b32f6183f42689c23f6a43a5e905ea0c6e939237fe905c62e4ed46e4fd029d512c43fb99549252b8841dc6eb811ec4')

prepare() {
  mv pyperclip-{$_commit,$pkgver}
}

build() {
  cd pyperclip-$pkgver
  python setup.py build
}

check() {
  cd pyperclip-$pkgver
  PYTHONPATH="$PWD"/build/lib xvfb-run py.test
}

package() {
  cd pyperclip-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE.txt -t "$pkgdir"/usr/share/licenses/$pkgname/
}

# vim:set ts=2 sw=2 et:
