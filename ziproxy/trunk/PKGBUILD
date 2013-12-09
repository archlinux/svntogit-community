# Contributor: Yejun Yang yejunx AT gmail DOT com

pkgname=ziproxy
pkgver=3.3.0
pkgrel=4
pkgdesc="forwarding, non-caching, compressing HTTP proxy server"
arch=('i686' 'x86_64')
url="http://ziproxy.sourceforge.net/"
license=('GPL2')
depends=('giflib' 'libpng' 'libjpeg' 'zlib' 'jasper' 'libsasl')
backup=(etc/ziproxy/ziproxy.conf
	etc/ziproxy/bo_exception.list
	etc/ziproxy/http.passwd
	etc/ziproxy/noprocess.list
	etc/ziproxy/replace.list
	etc/xinetd.d/ziproxy
	var/lib/ziproxy/error/400.html
	var/lib/ziproxy/error/404.html
	var/lib/ziproxy/error/407.html
	var/lib/ziproxy/error/408.html
	var/lib/ziproxy/error/409.html
	var/lib/ziproxy/error/500.html
	var/lib/ziproxy/error/503.html)
install=ziproxy.install
source=(http://downloads.sourceforge.net/project/ziproxy/ziproxy/ziproxy-$pkgver/ziproxy-$pkgver.tar.bz2
	ziproxy.logrotate
	ziproxy.xinetd
	build-fix.patch)
md5sums=('a8fda01591d455bb23c64c9c5ed3980d'
         'feb35264391c790cedd5e995182b5ff5'
         '3d2f9208b5ab6738c136049e1fd2e433'
         '0eb798863234ee0e9066812ef2a73539')

prepare() {
  cd $srcdir/$pkgname-$pkgver
  patch -p1 <$srcdir/build-fix.patch
}

build() {
  cd $srcdir/$pkgname-$pkgver
  [ -f Makefile ] || ./configure --prefix=/usr --with-jasper
  make
}

package() {
  cd $srcdir/$pkgname-$pkgver
  make DESTDIR=$pkgdir install

  install -d $pkgdir/var/lib/ziproxy/error
  install -d $pkgdir/etc/conf.d

  sed -i 's#var/ziproxy#var/lib/ziproxy#' etc/ziproxy/ziproxy.conf
  cp -a etc/ziproxy $pkgdir/etc/ziproxy
  install -m644 var/ziproxy/error/* $pkgdir/var/lib/ziproxy/error
  echo "ZIPROXY_ARGS=\"-c /etc/ziproxy/ziproxy.conf\"" >$pkgdir/etc/conf.d/ziproxy
  install -Dm0644 $srcdir/ziproxy.logrotate $pkgdir/etc/logrotate.d/ziproxy
  install -Dm0644 $srcdir/ziproxy.xinetd $pkgdir/etc/xinetd.d/ziproxy
}
