# Maintainer: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Max Mehl <aur at mehl dot mx>
# SPDX-FileCopyrightText: 2019 Max Mehl
# SPDX-License-Identifier: CC0-1.0

pkgname='python-license-expression'
_name=${pkgname#python-}
pkgver=21.6.14
pkgrel=3
pkgdesc='Utility to parse, normalize and compare license expressions'
arch=('any')
url='https://github.com/nexB/license-expression'
license=('Apache')
depends=('python' 'python-boolean.py')
makedepends=('python-setuptools' 'python-wheel' 'python-pip')
checkdepends=('python-pytest' 'python-pytest-xdist')
source=("$pkgname-$pkgver.tar.gz::$url/archive/v$pkgver.tar.gz")
sha512sums=('12c4333a53f30c73f123434c9e50ee50163a3bad5831e756cc1350c14daa062b939e8382f4bcf2fef11020f8bec5185f71302f3c68ae88cd59b8da9a5f2964f4')

prepare() {
  cd "$_name-$pkgver"

  # Fix file to comply with PEP-440
  sed -i "s/^fallback_version =.*/fallback_version = \"$pkgver\"/" pyproject.toml
}

build() {
  cd "$_name-$pkgver"
  python setup.py build
}

check() {
  cd "$_name-$pkgver"
  pytest
}

package() {
  cd "$_name-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
}

# vim: ts=2 sw=2 et:
