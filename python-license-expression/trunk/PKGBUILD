# Maintainer: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Max Mehl <aur at mehl dot mx>
# SPDX-FileCopyrightText: 2019 Max Mehl
# SPDX-License-Identifier: CC0-1.0

pkgname=python-license-expression
pkgver=21.6.14
pkgrel=5
pkgdesc='Utility to parse, normalize and compare license expressions'
arch=('any')
url='https://github.com/nexB/license-expression'
license=('Apache')
depends=(
  'python'
  'python-boolean.py'
)
makedepends=(
  'git'
  'python-setuptools'
  'python-wheel'
  'python-pip'
)
checkdepends=(
  'python-pytest'
  'python-pytest-xdist'
)
_commit='475a246eb3d5281cc63b90345fcba080bfefb21b'
source=("$pkgname::git+$url#commit=$_commit")
b2sums=('SKIP')

pkgver() {
  cd "$pkgname"

  git describe --tags | sed 's/^v//'
}

prepare() {
  cd "$pkgname"

  # Fix file to comply with PEP-440
  sed \
    -i pyproject.toml \
    -e "s/^fallback_version =.*/fallback_version = \"$pkgver\"/"

  # remove version constraint for python-boolean.py
  sed \
    -i setup.cfg \
    -e 's/\(boolean.py\).*$/\1/'
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
}
