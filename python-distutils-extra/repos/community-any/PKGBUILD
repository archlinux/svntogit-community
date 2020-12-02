# Maintainer: Angel 'angvp' Velasquez <angvp[at]archlinux.com.ve>
# Contributor: Abhishek Dasgupta <abhidg@gmail.com>

pkgname=python-distutils-extra
pkgver=2.39
pkgrel=8
pkgdesc='Enhancements to the Python build system'
arch=('any')
license=('GPL')
url='https://launchpad.net/python-distutils-extra'
depends=('intltool' 'python')
makedepends=('python-setuptools' 'intltool')
source=(https://launchpad.net/$pkgname/trunk/$pkgver/+download/$pkgname-$pkgver.tar.gz{,.asc})
# https://launchpad.net/python-distutils-extra/trunk/2.39/+download/python-distutils-extra-2.39.tar.gz.asc
        #$pkgname-$pkgver.tar.gz.sig::http://launchpad.net/$pkgname/trunk/$pkgver/+download/dist-$pkgname-$pkgver.tar.gz.sig)
validpgpkeys=('3DB46B55EFA59D40E6232148D14EF15DAFE11347')
md5sums=('16e06db0ef73a35b4bff4b9eed5699b5'
         'SKIP')

package() {
  cd "${srcdir}/$pkgname-$pkgver"
  python3 setup.py install --root="${pkgdir}"
}
