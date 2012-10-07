# $Id$ 
# Maintainer: Angel 'angvp' Velasquez <angvp[at]archlinux.com.ve>
# Contributor: Abhishek Dasgupta <abhidg@gmail.com>

pkgbase=python-distutils-extra
pkgname=('python-distutils-extra' 'python2-distutils-extra')
pkgver=2.37
pkgrel=1
pkgdesc='Enhancements to the Python build system'
arch=('any')
license=('GPL')
url='https://launchpad.net/python-distutils-extra'
makedepends=('python2-distribute' 'python-distribute' 'intltool')
source=(http://launchpad.net/$pkgbase/trunk/$pkgver/+download/$pkgbase-$pkgver.tar.gz
        $pkgbase-$pkgver.tar.gz.asc::http://launchpad.net/$pkgbase/trunk/$pkgver/+download/dist-$pkgbase-$pkgver.tar.gz.asc)
md5sums=('52cffcd6e8e17ed5aa2f9303683333ef'
         '774e8a89e7a05e1d1150f5e1bb4b34f9')

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
