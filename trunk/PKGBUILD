# Maintainer: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Max Mehl <aur at mehl dot mx>
# SPDX-FileCopyrightText: 2019 Max Mehl
# SPDX-License-Identifier: CC0-1.0

pkgname='python-boolean.py'
pkgver=4.0
pkgrel=2
pkgdesc='Implements boolean algebra in one module'
arch=('any')
url='https://github.com/bastikr/boolean.py'
license=('BSD')
depends=('python')
makedepends=('git' 'python-setuptools')
checkdepends=('python-pytest')
_commit='93589c505c256eead9757402e908fcfdc1bb5ec5'
source=("$pkgname::git+$url#commit=$_commit")
b2sums=('SKIP')

pkgver() {
  cd "$pkgname"

  git describe --tags | sed 's/^v//'
}

build() {
  cd "$pkgname"

  python setup.py build
}

check() {
  cd "$pkgname"

  pytest
}

package() {
  cd "$pkgname"

  python setup.py install --root="$pkgdir" --optimize=1 --skip-build

  install -Dm644 -t "$pkgdir/usr/share/licenses/$pkgname" LICENSE.txt
}

# vim: ts=2 sw=2 et:
