# Maintainer: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Max Mehl <aur at mehl dot mx>
# SPDX-FileCopyrightText: 2019 Max Mehl
# SPDX-License-Identifier: CC0-1.0

pkgname='python-boolean.py'
_name=${pkgname#python-}
pkgver=3.8
pkgrel=5
pkgdesc='Implements boolean algebra in one module'
arch=('any')
url='https://github.com/bastikr/boolean.py'
license=('BSD')
depends=('python')
makedepends=('python-setuptools')
source=("$pkgname-$pkgver.tar.gz::https://github.com/bastikr/boolean.py/archive/v$pkgver.tar.gz")
sha512sums=('d41ce9a05743342c116d68b88ea36be316ac9fc190a8451aca97b52fde60c58ec49d36d2dee071f83fb5f6ad49337da80bf9de1bf3d479b46386fd87e4cf2f14')

build() {
  cd "$_name-$pkgver"
  python setup.py build
}

check() {
  cd "$_name-$pkgver"
  python3 -m unittest discover --verbose
}

package() {
  cd "$_name-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build

  install -Dm644 -t "$pkgdir/usr/share/licenses/$pkgname" LICENSE.txt
}

# vim: ts=2 sw=2 et:
