# $Id$
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Jonathan Wiersma <archaur at jonw dot org>

pkgname=virt-manager
pkgver=0.8.5
pkgrel=3
pkgdesc="A desktop user interface for managing virtual machines."
arch=('any')
url="http://virt-manager.et.redhat.com"
license=('GPL')
depends=('dbus-python' 'python-gnomedesktop' 'libvirt' 'libxml2' 'vte' 'virtinst' 'gtk-vnc' 'rarian' 'gconf'
	 'yajl' 'librsvg' 'gnome-python')
makedepends=('gnome-doc-utils' 'intltool>=0.35.0')
optdepends=('x11-ssh-askpass: for ssh authentication to remote servers')
install=virt-manager.install
source=("http://virt-manager.et.redhat.com/download/sources/$pkgname/$pkgname-$pkgver.tar.gz")
md5sums=('038668be9e5edcb86ebae2495240b6ff')

build() {
	cd $srcdir/$pkgname-$pkgver || return 1
	export LDFLAGS=-lX11
	./configure --prefix=/usr \
		--sysconfdir=/etc \
		--libexec=/usr/lib/$pkgname \
		--localstatedir=/var || return 1
	make || return 1
	make GCONF_DISABLE_MAKEFILE_SCHEMA_INSTALL=1 DESTDIR=$pkgdir install || return 1
	# Set-up schema file in correct location
	install -m755 -d $pkgdir/usr/share/gconf/schemas || return 1
	gconf-merge-schema \
		$pkgdir/usr/share/gconf/schemas/$pkgname.schemas \
		$pkgdir/etc/gconf/schemas/*.schemas || return 1
	rm -rf $pkgdir/etc/gconf/schemas
	rmdir --ignore-fail-on-non-empty $pkgdir/etc/gconf $pkgdir/etc || return 1
}
