# $Id$
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Daniel Micay <danielmicay@gmail.com>
# Contributor: Jonathan Wiersma <archaur at jonw dot org>

pkgbase=virt-manager
pkgname=(virt-install virt-manager)
pkgver=1.2.0
pkgrel=2
pkgdesc="Console user interface for managing virtual machines"
arch=('any')
url="http://virt-manager.org/"
license=('GPL')
depends=('python2' 'libvirt-python' 'libxml2' 'libvirt' 'urlgrabber'
	 'libosinfo' 'python2-ipaddr' 'python2-gobject')
makedepends=('intltool>=0.35.0'
	     'dbus-python' 'gtk-vnc' 'rarian'
	     'gconf' 'yajl' 'librsvg' 'python2-gconf' 'libuser'
	     'python2-ipy' 'newt-syrup' 'openbsd-netcat' 'x11-ssh-askpass'
	     'graphite' 'spice-gtk3'
	     'libvirt-glib' 'vte3')
source=("http://virt-manager.org/download/sources/virt-manager/virt-manager-$pkgver.tar.gz")
md5sums=('89e6c816054f3a3751100a8d79ec97c2')

build() {
  cd "$srcdir/$pkgbase-$pkgver"
  python2 setup.py build
}

package_virt-install() {
  cd "$srcdir/$pkgbase-$pkgver"
  python2 setup.py install --root "$pkgdir"
}

package_virt-manager() {
  pkgdesc="Desktop user interface for managing virtual machines"
  install=virt-manager.install
  depends=('virt-install'
	    'python2' 'libvirt-python' 'libxml2' 'libvirt' 'urlgrabber'
	    'dbus-python' 'gtk-vnc' 'rarian'
	    'gconf' 'yajl' 'librsvg' 'python2-gconf' 'libuser'
	    'python2-ipy' 'newt-syrup' 'openbsd-netcat' 'x11-ssh-askpass'
	    'graphite' 'spice-gtk3'
	    'libvirt-glib' 'vte3')
}
