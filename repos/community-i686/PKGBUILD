# $Id$
# Maintainer: BlackEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Bernhard Walle <bernhard.walle@gmx.de>

pkgname=lcdproc
pkgver=0.5.6
pkgrel=5
pkgdesc="Utility to drive one or more LCD (and LCD-like) devices"
arch=('i686' 'x86_64')
url="http://lcdproc.omnipotent.net/"
license=('GPL')
depends=('libftdi-compat')
makedepends=('g15daemon')
optdepends=(
	'perl: needed for some lcdproc tools'
	'g15daemon: needed if you want g15 support'
)
backup=(
	'etc/LCDd.conf'
	'etc/lcdexec.conf'
	'etc/lcdproc.conf'
	'etc/lcdvc.conf'
)
source=(
	"http://downloads.sourceforge.net/$pkgname/$pkgname-$pkgver.tar.gz"
	'lcdd.service'
)
sha256sums=('bd2f43c30ff43b30f43110abe6b4a5bc8e0267cb9f57fa97cc5e5ef9488b984a'
            '0acdc0fb9668e6d5e023349874301153a16935e1ad757d550c426a9a7ac64638')

build() {
	cd "$pkgname-$pkgver"
	./configure \
		--prefix=/usr \
		--sbindir=/usr/bin \
		--sysconfdir=/etc \
		--enable-libusb \
		--enable-lcdproc-menus \
		--enable-stat-smbfs \
		--enable-drivers=all
	make
}

package() {
	cd "$pkgname-$pkgver"
	make DESTDIR="$pkgdir" install
	sed -e "s/server\/drivers\//\/usr\/lib\/lcdproc\//g" -i "$pkgdir/etc/LCDd.conf"
	install -Dm644 "$srcdir/lcdd.service" "$pkgdir/usr/lib/systemd/system/lcdd.service"
}
