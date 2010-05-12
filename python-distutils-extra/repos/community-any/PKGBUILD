# $Id$ 
# Maintainer: Angel 'angvp' Velasquez <angvp[at]archlinux.com.ve>
# Contributor: Abhishek Dasgupta <abhidg@gmail.com>

pkgname=python-distutils-extra
pkgver=2.19
pkgrel=1
pkgdesc="Enhancements to the Python build system"
arch=(any)
license=("GPL")
url="http://packages.qa.debian.org/p/python-distutils-extra.html"
depends=('intltool' 'python>=2.6')
makedepends=('setuptools')
source=(http://ftp.de.debian.org/debian/pool/main/p/${pkgname}/${pkgname}_${pkgver}.tar.gz)
md5sums=('f0c2f70ebccb1bd838d7014ff8dac1d9')

build() {
  cd "${srcdir}/debian"
  python setup.py install --root="${pkgdir}" || return 1
}

