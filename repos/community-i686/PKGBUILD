# $Id$
# Maintainer: BlackEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Bernhard Walle <bernhard.walle@gmx.de>

pkgname=lcdproc
pkgver=0.5.7
pkgrel=1
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
sha256sums=('843007d377adc856529ed0c7c42c9a7563043f06b1b73add0372bba3a3029804'
            '0acdc0fb9668e6d5e023349874301153a16935e1ad757d550c426a9a7ac64638')
