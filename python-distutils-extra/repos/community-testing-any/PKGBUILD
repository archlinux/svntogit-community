# $Id$ 
# Maintainer: Angel 'angvp' Velasquez <angvp[at]archlinux.com.ve>
# Contributor: Abhishek Dasgupta <abhidg@gmail.com>

pkgname=python-distutils-extra
pkgver=2.20
pkgrel=1
pkgdesc="Enhancements to the Python build system"
arch=(any)
license=("GPL")
url="http://packages.qa.debian.org/p/python-distutils-extra.html"
depends=('intltool' 'python2')
makedepends=('setuptools')
source=(http://ftp.de.debian.org/debian/pool/main/p/${pkgname}/${pkgname}_${pkgver}.tar.gz)
md5sums=('0b0939579047ee256e77e4f8fe345c3b')

build() {
  cd "${srcdir}/debian"

  # python2 fix
  sed -i 's_#!/usr/bin/env python_#!/usr/bin/env python2_' DistUtilsExtra/command/build_extra.py

  python2 setup.py install --root="${pkgdir}"
}

