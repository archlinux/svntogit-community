#
# quagga routing suite PKGBUILD
#
# Maintainer: Xavier Devlamynck <magicrhesus@ouranos.be>
# Contributor: shild <shildv@gmail.com> 
# Contributor: Georg Grabler (STiAT) <ggrabler@gmail.com>
# Contributor: Bart Kos, bro at fast-stable-secure dot net
# Contributor: HomeCreate <homecreate@list.ru>
# Contributor: Damjan Georgievski, gdamjan at gmail dot com
#

pkgname=quagga
pkgver=0.99.20
pkgrel=1
pkgdesc="Advanced routing protocol suite. Includes BGP4 OSPF2 OSPF3 RIP protocols implementations"
arch=('i686' 'x86_64')
url="http://www.quagga.net"
license=('GPL2')
depends=('libcap>=2.17' 'libnl' 'net-snmp' 'readline>=6.0.003-3' 'iproute' 'cpulimit' 'autoconf')
backup=('etc/quagga.d/zebra.conf' 'etc/quagga.d/ripd.conf' 'etc/quagga.d/ripngd.conf' 'etc/quagga.d/ospfd.conf' 'etc/quagga.d/ospf6d.conf' 'etc/quagga.d/bgpd.conf' 'etc/conf.d/quagga')
install=quagga.install

source=(http://www.quagga.net/download/$pkgname-$pkgver.tar.gz zebra ripd ripngd ospfd ospf6d bgpd quagga.conf 
        patch-zebra_rib.c.patch patch-interface.c.patch patch-ipforward_sysctl.c.patch patch-Makefile.in.patch)

md5sums=('64cc29394eb8a4e24649d19dac868f64'
	 '0bb8662ffb60106ca5476b559afe6fa9'
	 '892055cfd46b7bd89fd13cf4c446c07e'
	 '12075ca726cb8e401f601b17f375b88e'
	 '5069f9e6ade2e1acc9335da38b2be310'
	 'f44cdb3354e8bd70039cab07c3363cf4'
	 '83327d4d078a8d90b7e8e3c3f90b92e8'
	 '1fd63dc935eece30d871c7d007b1c432'
	 '1cbcf60a637b2577dee4d6df711e1247'
	 'c9ae6cecfc8bbf591194857b51572604'
	 '76ae0de530e7ef287507f0e4b3bbe4ed'
   'a16065f40a229e711d0a0e37340eff15')

build() {
    cd $srcdir/$pkgname-$pkgver

  msg "Patching..."
  # ipv6 patch
  cat $srcdir/patch-ipforward_sysctl.c.patch | patch -p1
  # ip remove patch
  cat $srcdir/patch-interface.c.patch | patch -p1
  # reordering libs patch
  cat $srcdir/patch-Makefile.in.patch | patch -p1
  # rib delete route patch
  cat $srcdir/patch-zebra_rib.c.patch | patch -p1

  msg "Configuring..."
  ./configure --prefix=/usr \
		--sysconfdir=/etc/quagga.d \
		--localstatedir=/var/lib/quagga \
		--enable-ipv6 \
		--enable-snmp \
		--enable-netlink \
		--enable-tcp-zebra \
		--enable-opaque-lsa \
		--enable-ospf-te \
		--enable-multipath=0 \
		--enable-user=quagga \
		--enable-group=quagga \
		--enable-irdp \
		--enable-pcreposix \
		--enable-rtadv \
    --enable-vtysh
    
    msg "Building..."
    make

    msg "Installing..."
    make DESTDIR=$pkgdir PREFIX=$pkgdir install

    for line in bgpd ospfd ospf6d zebra ripd ripngd
    do
  	install -D -m 755 -o root -g root $srcdir/$line $pkgdir/etc/rc.d/$line
	
	  touch $pkgdir/etc/quagga.d/$line.conf
	  echo "password quagga" > $pkgdir/etc/quagga.d/$line.conf
    done

    mkdir -p $pkgdir/etc/conf.d
    install -D -m 644 -o root -g root $srcdir/quagga.conf $pkgdir/etc/conf.d/quagga

    chmod 775 $pkgdir/etc/quagga.d
    rm $pkgdir/usr/share/info/dir
    
    mkdir -p $pkgdir/var/lib/quagga
    chmod 775 $pkgdir/var/lib/quagga
    mkdir -p $pkgdir/var/log/quagga
    
    rm $pkgdir/usr/lib/{libospfapiclient,libospf,libzebra}.la
}

# vim:set ts=2 sw=2 et:
