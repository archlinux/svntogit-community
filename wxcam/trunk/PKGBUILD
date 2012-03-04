pkgname=wxcam
pkgver=1.1
pkgrel=1
arch=('i686' 'x86_64')
license=(GPL)
pkgdesc="Webcam application for linux"
# version of CImg library needed to compile wxcam -
# http://cimg.sourceforge.net/
_CImg_ver=1.4.9
url="http://wxcam.sourceforge.net"
makedepends=('intltool>=0.35.0')
depends=('libglade' 'mjpegtools' 'perlxml' 'wxgtk' 'xvidcore')
source=(http://downloads.sourceforge.net/wxcam/${pkgname}-${pkgver}.tar.bz2
	http://downloads.sourceforge.net/cimg/CImg-${_CImg_ver}.zip)
md5sums=('c9ea8991b6375c1709a7ce4e61fcc263'
         'a07cba03f6d66a9970e0b3fcc230bddc')

build() {
    cp $startdir/src/CImg-${_CImg_ver}/CImg.h $startdir/src/$pkgname-$pkgver
    cd $startdir/src/$pkgname-$pkgver
    ./configure --prefix=/usr || return 1
    make || return 1
    make DESTDIR=$startdir/pkg install
}
