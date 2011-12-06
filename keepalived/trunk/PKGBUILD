# Contributor: Andrea Zucchelli <zukka77@gmail.com>
pkgname=keepalived
pkgver=1.2.2
pkgrel=1
pkgdesc="implements an independent VRRPv2 stack and a userspace daemon for LVS cluster nodes healthchecks and LVS directors failover"
arch=('i686' 'x86_64')
url="http://www.keepalived.org/"
license=('GPL')
groups=()
backup=('etc/keepalived/keepalived.conf' 'etc/conf.d/keepalived')
depends=('openssl' 'popt' 'libnl')
source=("http://www.keepalived.org/software/$pkgname-$pkgver.tar.gz"
        "keepalived"
	"ip_vs_moved.patch"
	)


build() {
  cd "$srcdir/$pkgname-$pkgver"
  #patch -p0 -i "$startdir/src/vrrp_arp.patch"
  #export CPPFLAGS=-I/usr/src/linux-`uname -r`/include
  patch -p1 -i $srcdir/ip_vs_moved.patch
  ./configure --prefix=/usr --sysconfdir=/etc --mandir=/usr/share/man
  make || return 1
  make DESTDIR="$pkgdir" install
  install -d -m 755 "$pkgdir/etc/rc.d"
  rm  "$pkgdir/etc/rc.d/init.d/keepalived"
  rmdir "$pkgdir/etc/rc.d/init.d"
  cp "$srcdir/keepalived" "$pkgdir/etc/rc.d"
  mv "$pkgdir/etc/keepalived/keepalived.conf" "$pkgdir/etc/keepalived/keepalived.conf.sample"
  mv "$pkgdir/etc/sysconfig" "$pkgdir/etc/conf.d"
}
md5sums=('f68327ca142616a8463d2d105db122cd'
         '5d01008994157f47968e8bd82fb366d5'
         '87ee19c85adaedd3eb11bea8a5865d47')
