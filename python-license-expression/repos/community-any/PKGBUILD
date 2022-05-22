# Maintainer: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Max Mehl <aur at mehl dot mx>
# SPDX-FileCopyrightText: 2019 Max Mehl
# SPDX-License-Identifier: CC0-1.0

pkgname=python-license-expression
pkgver=30.0.0
pkgrel=1
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
_commit='5f4febb6df2b644706839e42ba4310de9e2dccba'
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
