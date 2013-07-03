# $Id$
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Jonathan Wiersma <archaur at jonw dot org>

pkgname=virt-manager
pkgver=0.10.0
pkgrel=2
pkgdesc="Desktop user interface for managing virtual machines"
arch=('any')
url="http://virt-manager.et.redhat.com"
license=('GPL')
depends=('dbus-python' 'libvirt' 'libxml2' 'vte' 'gtk-vnc' 'rarian'
         'gconf' 'yajl' 'librsvg' 'python2' 'python2-gconf' 'libuser'
         'python2-ipy' 'newt-syrup' 'openbsd-netcat' 'x11-ssh-askpass'
         'hicolor-icon-theme' 'graphite' 'python2-ipaddr' 'spice-gtk3'
         'libvirt-glib' 'python2-gobject' 'urlgrabber' 'vte3')
makedepends=('gnome-doc-utils' 'intltool>=0.35.0')
conflicts=('virtinst')
replaces=('virtinst')
install=virt-manager.install
source=("http://virt-manager.et.redhat.com/download/sources/$pkgname/$pkgname-$pkgver.tar.gz")
md5sums=('e23b8d2a7623b4e8e256c25735f332c8')

prepare() {
  cd "$srcdir/$pkgname-$pkgver"
  sed -i 's#bin/python#bin/python2#' virt-*
}

build() {
  cd "$srcdir/$pkgname-$pkgver"
  python2 setup.py build
}

package() {
  cd "$srcdir/$pkgname-$pkgver"
  python2 setup.py install --root "$pkgdir"
}

# vim:set ts=2 sw=2 et:
