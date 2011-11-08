# $Id$
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Jonathan Wiersma <archaur at jonw dot org>

pkgname=virt-manager
pkgver=0.9.0
pkgrel=2
pkgdesc="A desktop user interface for managing virtual machines."
arch=('any')
url="http://virt-manager.et.redhat.com"
license=('GPL')
depends=('dbus-python' 'libvirt' 'libxml2' 'vte' 'virtinst' 'gtk-vnc' 'rarian' 'gconf'
	 'yajl' 'librsvg' 'python2' 'python2-gconf')
makedepends=('gnome-doc-utils' 'intltool>=0.35.0')
optdepends=('x11-ssh-askpass: for ssh authentication to remote servers'
	    'libuser: for virt-manager-tui'
	    'python2-ipy: for virt-manager-tui'
	    'newt-syrup: for virt-manager-tui')
install=virt-manager.install
source=("http://virt-manager.et.redhat.com/download/sources/$pkgname/$pkgname-$pkgver.tar.gz"
	"openbsd-netcat-default.patch")
md5sums=('a10331b467f92f4134a39bf636e04adc'
         'd4aad201758c2275e4237f5239d7ffb2')

build() {
  cd $srcdir/$pkgname-$pkgver
  export LDFLAGS=-lX11
  sed -i 's#python#python2#' src/virt-manager.in src/virt-manager-tui.in
  patch -p1 <$srcdir/openbsd-netcat-default.patch
  ./configure --prefix=/usr \
	--sysconfdir=/etc \
	--libexec=/usr/lib/$pkgname \
	--localstatedir=/var
  make
  make GCONF_DISABLE_MAKEFILE_SCHEMA_INSTALL=1 DESTDIR=$pkgdir install
  # Set-up schema file in correct location
  install -m755 -d $pkgdir/usr/share/gconf/schemas
  gconf-merge-schema \
	$pkgdir/usr/share/gconf/schemas/$pkgname.schemas \
	$pkgdir/etc/gconf/schemas/*.schemas
  rm -rf $pkgdir/etc/gconf/schemas
  rmdir --ignore-fail-on-non-empty $pkgdir/etc/gconf $pkgdir/etc
}
