# Maintainer: Balló György <ballogyor+arch at gmail dot com>
# Contributor: Johannes Pfau <johannespfau at gmail dot com>

pkgname=notify-osd
pkgver=0.9.35+16.04.20160415
pkgrel=3
pkgdesc="Canonical's on-screen-display notification agent, implementing the freedesktop.org Desktop Notifications Specification with semi-transparent click-through bubbles"
arch=('x86_64')
url="https://launchpad.net/notify-osd"
license=('GPL')
depends=('libwnck3' 'dbus-glib' 'gsettings-desktop-schemas')
makedepends=('gnome-common' 'libnotify')
provides=('notification-daemon')
source=(https://launchpad.net/ubuntu/+archive/primary/+files/${pkgname}_$pkgver.orig.tar.gz)
sha256sums=('119fd662e4cbfeec492c1f96e26687dbfb5986076114bda488807358e54cfb53')

prepare() {
  NOCONFIGURE=1 ./autogen.sh
}

build() {
  ./configure --prefix=/usr --sysconfdir=/etc --localstatedir=/var --libexecdir=/usr/lib/$pkgname \
              --disable-schemas-compile
  make
}

package() {
  make DESTDIR="$pkgdir" install

  # Remove readme file from non-standard location
  rm "$pkgdir/usr/share/notify-osd/icons/hicolor/scalable/status/README"
}
