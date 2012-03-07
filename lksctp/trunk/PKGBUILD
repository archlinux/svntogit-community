# Contributer: Nicolas Martyanoff <khaelin@gmail.com>
pkgname=lksctp-tools
pkgver=1.0.11
pkgrel=2
pkgdesc="An implementation of the SCTP protocol"
arch=('i686' 'x86_64')
url="http://lksctp.sourceforge.net/"
license=('GPL')

source=(http://downloads.sourceforge.net/sourceforge/lksctp/"${pkgname}"-"${pkgver}".tar.gz)
md5sums=('e9cf6c57402c9d4f1173a9529466e16d')

build() {
   cd $startdir/src/"${pkgname}"-"${pkgver}"
   ./configure --prefix=/usr
   make || return 1
   make DESTDIR=${startdir}/pkg install
}
