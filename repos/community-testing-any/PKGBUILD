# $Id$
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Daniel Micay <danielmicay@gmail.com>
# Contributor: Jonathan Wiersma <archaur at jonw dot org>

pkgname=virt-manager
pkgver=1.1.0
pkgrel=3
pkgdesc="Desktop user interface for managing virtual machines"
arch=('any')
url="http://virt-manager.org/"
license=('GPL')
depends=('dbus-python' 'libvirt' 'libxml2' 'gtk-vnc' 'rarian'
         'gconf' 'yajl' 'librsvg' 'python2' 'python2-gconf' 'libuser'
         'python2-ipy' 'newt-syrup' 'openbsd-netcat' 'x11-ssh-askpass'
         'gnome-icon-theme' 'graphite' 'python2-ipaddr' 'spice-gtk3'
         'libvirt-glib' 'python2-gobject' 'urlgrabber' 'vte3'
         'libvirt-python' 'libosinfo')
makedepends=('gnome-doc-utils' 'intltool>=0.35.0')
conflicts=('virtinst')
replaces=('virtinst')
install=virt-manager.install
source=("http://virt-manager.org/download/sources/virt-manager/virt-manager-$pkgver.tar.gz")
md5sums=('baf6eaa88b02bdd7a3c2fdd293eeb6ac')

build() {
  cd "$srcdir/$pkgname-$pkgver"
  python2 setup.py build
}

package() {
  cd "$srcdir/$pkgname-$pkgver"
  python2 setup.py install --root "$pkgdir"
}
