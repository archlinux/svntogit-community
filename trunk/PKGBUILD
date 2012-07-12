# $Id$
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Jonathan Wiersma <archaur at jonw dot org>

pkgname=virt-manager
pkgver=0.9.3
pkgrel=1
pkgdesc="Desktop user interface for managing virtual machines"
arch=('any')
url="http://virt-manager.et.redhat.com"
license=('GPL')
depends=('dbus-python' 'libvirt' 'libxml2' 'vte' 'virtinst' 'gtk-vnc' 'rarian'
         'gconf' 'yajl' 'librsvg' 'python2' 'python2-gconf' 'libuser'
         'python2-ipy' 'newt-syrup' 'openbsd-netcat' 'x11-ssh-askpass'
         'hicolor-icon-theme')
makedepends=('gnome-doc-utils' 'intltool>=0.35.0')

# When executables that comes with the package crash, are deps optional?
# It may be a matter of taste, but we got at least one crash bug report.
#optdepends=('x11-ssh-askpass: for ssh authentication to remote servers'
#	    'libuser: for virt-manager-tui'
#	    'python2-ipy: for virt-manager-tui'
#	    'newt-syrup: for virt-manager-tui'
#	    'openbsd-netcat: for remote server access')

install=virt-manager.install
source=("http://virt-manager.et.redhat.com/download/sources/$pkgname/$pkgname-$pkgver.tar.gz"
        "openbsd-netcat-default.patch")
md5sums=('4c03f1628c76a891f45c0375bf5590da'
         '76d5a0d6c3bf60e98df3ffe76248745e')

build() {
  cd "$srcdir/$pkgname-$pkgver"

  export LDFLAGS=-lX11
  sed -i 's#python#python2#' src/virt-manager.in src/virt-manager-tui.in
  patch -p1 < "$srcdir/openbsd-netcat-default.patch"
  [ -f install-sh ] || automake --add-missing || true
  ./configure --prefix=/usr \
	--sysconfdir=/etc \
	--libexec="/usr/lib/$pkgname" \
	--localstatedir=/var
  make
}

package() {
  cd "$srcdir/$pkgname-$pkgver"

  make GCONF_DISABLE_MAKEFILE_SCHEMA_INSTALL=1 DESTDIR="$pkgdir" install
  # Set-up schema file in correct location
  install -m755 -d "$pkgdir/usr/share/gconf/schemas"
  gconf-merge-schema \
	"$pkgdir/usr/share/gconf/schemas/$pkgname.schemas" \
	"$pkgdir/etc/gconf/schemas/"*.schemas
  rm -rf "$pkgdir/etc/gconf/schemas"
  rmdir --ignore-fail-on-non-empty "$pkgdir/etc/gconf" "$pkgdir/etc"
}

# vim:set ts=2 sw=2 et:
