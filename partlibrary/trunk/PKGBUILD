# Maintainer: Stefan Husmann <stefan-husmann@t-online.de>
# Contributor: Giovanni Scafora <linuxmania@gmail.com>

pkgname=partlibrary
pkgver=2.1.2.8
pkgrel=3
pkgdesc="Collection of CAD files that can be used from the library browser of QCad"
arch=('any')
url="http://www.ribbonsoft.com/qcad_library.html"
license=('GPL')
depends=('sh')
install=partlibrary.install
source=(ftp://anonymous:anonymous@ribbonsoft.com/archives/$pkgname/$pkgname-$pkgver-1.tar.gz)
md5sums=('e1df98084317b13bfc193fecba9d6790')

package () {
  cd $srcdir/$pkgname-2.1.2.8-1
  install -d -m755 $pkgdir/usr/share/qcad/$pkgname
  cp -r architecture electrical electronics mechanical \
    misc processing templates zipf_libs \
    $pkgdir/usr/share/qcad/$pkgname
  chmod 644 \
    $pkgdir/usr/share/qcad/$pkgname/mechanical/notches/{form_a.dxf,form_c.dxf}
  chmod 755 $pkgdir/usr/share/qcad/$pkgname/mechanical/screws/chc
}
