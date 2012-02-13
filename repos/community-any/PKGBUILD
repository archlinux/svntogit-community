# $Id$
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Jonathan Wiersma <archaur at jonw dot org>

pkgname=virt-manager
pkgver=0.9.1
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
sha256sums=('db0de808efa5d6bae0bdc2db796e58ea79f9e1db20d9a5a5977b28b4b85d4321'
            'df285000ce6199a19fbd898787628c2f60f22049f225015392dfee70215acf35')
sha256sums=('15e064167ba5ff84ce6fc8790081d61890430f2967f89886a84095a23e40094a'
            'df285000ce6199a19fbd898787628c2f60f22049f225015392dfee70215acf35')
sha256sums=('15e064167ba5ff84ce6fc8790081d61890430f2967f89886a84095a23e40094a'
            'be763a87a8316126950f12f022336ce20b77c80796ce1b24a8c1ad2ac0eeadd5')

build() {
  cd "$srcdir/$pkgname-$pkgver"

  export LDFLAGS=-lX11
  sed -i 's#python#python2#' src/virt-manager.in src/virt-manager-tui.in
  patch -p1 < "$srcdir/openbsd-netcat-default.patch"
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
