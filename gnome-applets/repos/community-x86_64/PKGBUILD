# Maintainer: Balló György <ballogyor+arch at gmail dot com>
# Contributor: Jan de Groot <jgc@archlinux.org>

pkgname=gnome-applets
pkgver=3.46.0
pkgrel=1
pkgdesc='Small applications for the GNOME Panel'
arch=('x86_64')
url='https://wiki.gnome.org/Projects/GnomeApplets'
license=('GPL')
depends=('cpupower' 'gnome-panel' 'libgtop' 'tracker3' 'upower')
makedepends=('itstool')
optdepends=('tracker3-miners: Search bar')
source=("https://download.gnome.org/sources/$pkgname/${pkgver%.*}/$pkgname-$pkgver.tar.xz")
sha256sums=('4f0463ca80f30940385b309c1e6902588c71d97150c6540e834f374e4d27acf7')

prepare() {
  cd $pkgname-$pkgver
  # Use correct D-Bus config location
  sed -i '/^dbus_confdir =/ s/sysconfdir/datadir/' gnome-applets/cpufreq/cpufreq-selector/Makefile.am
  autoreconf -fi
}

build() {
  cd $pkgname-$pkgver
  ./configure --prefix=/usr --disable-schemas-compile --enable-compile-warnings=minimum
  sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool
  make
}

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
