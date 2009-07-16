# $Id: PKGBUILD,v 1.11 2009/05/28 14:18:09 Neverth Exp $
# Contributor: Pierre Schmitz <pierre@archlinux.de>
# Maintainer: Mikko Seppälä <t-r-a-y@mbnet.fi>
_pkgsourcename=mesa
pkgname=lib32-$_pkgsourcename
pkgver=7.4.2
pkgrel=1
pkgdesc="Mesa OpenGL library"
arch=(x86_64)
url="http://mesa3d.sourceforge.net"
license=('LGPL')
groups=('lib32')
depends=('lib32-libgl' 'lib32-gcc' 'lib32-libxt')
source=(ftp://ftp.archlinux.org/extra/os/i686/$_pkgsourcename-$pkgver-$pkgrel-i686.pkg.tar.gz)
md5sums=('e7407a4312901c12b0106dd19fe752f6')

build() {
	cd $startdir/src
	mkdir -p $startdir/pkg/opt/lib32/usr/lib
	cp -dp usr/lib/*.so* $startdir/pkg/opt/lib32/usr/lib
}
