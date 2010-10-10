# $Id$ 
# Maintainer: Angel 'angvp' Velasquez <angvp[at]archlinux.com.ve>
# Contributor: Abhishek Dasgupta <abhidg@gmail.com>

pkgname=python-distutils-extra
pkgver=2.22
pkgrel=2
pkgdesc='Enhancements to the Python build system'
arch=('any')
license=('GPL')
url='http://packages.qa.debian.org/p/python-distutils-extra.html'
depends=('intltool' 'python2')
makedepends=('setuptools')
source=(http://launchpad.net/$pkgname/trunk/$pkgver/+download/$pkgname-$pkgver.tar.gz)
md5sums=('c085b71263c37af48824f8a353475181')

build() {
  cd "${srcdir}/$pkgname-$pkgver"

  # python2 fix
  sed -i 's_#!/usr/bin/env python_#!/usr/bin/env python2_' setup.py test/auto.py
  sed -i 's_\(subprocess.call.*\)python_\1python2_' DistUtilsExtra/command/build_kdeui.py

  python2 setup.py install --root="${pkgdir}"
}
# vim:set ts=2 sw=2 et:
