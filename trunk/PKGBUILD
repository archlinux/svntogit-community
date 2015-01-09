# $Id$ 
# Maintainer: Angel 'angvp' Velasquez <angvp[at]archlinux.com.ve>
# Contributor: Abhishek Dasgupta <abhidg@gmail.com>

pkgbase=python-distutils-extra
pkgname=('python-distutils-extra' 'python2-distutils-extra')
pkgver=2.38
pkgrel=2
pkgdesc='Enhancements to the Python build system'
arch=('any')
license=('GPL')
url='https://launchpad.net/python-distutils-extra'
makedepends=('python2-setuptools' 'python-setuptools' 'intltool')
source=(http://launchpad.net/$pkgbase/trunk/$pkgver/+download/$pkgbase-$pkgver.tar.gz
        $pkgbase-$pkgver.tar.gz.asc::http://launchpad.net/$pkgbase/trunk/$pkgver/+download/dist-$pkgbase-$pkgver.tar.gz.asc)
validpgpkeys=('3DB46B55EFA59D40E6232148D14EF15DAFE11347')
md5sums=('4e4c9bee92a3ca8bfd915f3adcf14648'
         'SKIP')

package_python2-distutils-extra() {
  depends=('intltool' 'python2')

  cd "${srcdir}/$pkgbase-$pkgver"
  python2 setup.py install --root="${pkgdir}"
}

package_python-distutils-extra() {
  depends=('intltool' 'python')

  cd "${srcdir}/$pkgbase-$pkgver"
  python3 setup.py install --root="${pkgdir}"
}
