# $Id: PKGBUILD,v 1.3 2009/01/01 14:53:47 abhidg Exp $
# Maintainer: Abhishek Dasgupta <abhidg@gmail.com>
# Contributor: Abhishek Dasgupta <abhidg@gmail.com>

pkgname=python-distutils-extra
pkgver=1.91.2
pkgrel=2
pkgdesc="Enhancements to the Python build system"
arch=(i686 x86_64)
license=("GPL")
url="http://www.glatzor.de/projects/python-distutils-extra/"
depends=('intltool' 'python>=2.6')
makedepends=('setuptools')
source=(http://ftp.de.debian.org/debian/pool/main/p/${pkgname}/${pkgname}_${pkgver}.tar.gz)

build() {
  cd "${srcdir}/debian"
  python setup.py install --root="${pkgdir}" || return 1
}

md5sums=('413ebd3e52c45437eaa36d1d9e6912fd')
