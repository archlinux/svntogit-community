# Contributor: Igor Scabini <furester @ gmail.com>

pkgname=cython
pkgver=0.13
pkgrel=3
pkgdesc="C-Extensions for Python "
arch=(i686 x86_64)
url="http://www.cython.org"
license=('APACHE')
depends=('python2')
source=("http://cython.org/release/Cython-$pkgver.tar.gz")
md5sums=('ed2ec5e0df60a6b8e500bedf93bb1feb')

build() {
  cd $srcdir/Cython-$pkgver
  python2 setup.py install --root=$pkgdir
}
