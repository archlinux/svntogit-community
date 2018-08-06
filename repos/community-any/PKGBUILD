# $Id$ 
# Maintainer: Angel 'angvp' Velasquez <angvp[at]archlinux.com.ve>
# Contributor: Abhishek Dasgupta <abhidg@gmail.com>

pkgbase=python-distutils-extra
pkgname=('python-distutils-extra' 'python2-distutils-extra')
pkgver=2.39
pkgrel=3
pkgdesc='Enhancements to the Python build system'
arch=('any')
license=('GPL')
url='https://launchpad.net/python-distutils-extra'
makedepends=('python2-setuptools' 'python-setuptools' 'intltool')
source=(http://launchpad.net/$pkgbase/trunk/$pkgver/+download/$pkgbase-$pkgver.tar.gz{,.asc})
# https://launchpad.net/python-distutils-extra/trunk/2.39/+download/python-distutils-extra-2.39.tar.gz.asc
        #$pkgbase-$pkgver.tar.gz.sig::http://launchpad.net/$pkgbase/trunk/$pkgver/+download/dist-$pkgbase-$pkgver.tar.gz.sig)
validpgpkeys=('3DB46B55EFA59D40E6232148D14EF15DAFE11347')
md5sums=('16e06db0ef73a35b4bff4b9eed5699b5'
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
