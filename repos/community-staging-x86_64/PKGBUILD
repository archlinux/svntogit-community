# Maintainer: Balló György <ballogyor+arch at gmail dot com>
# Contributor: Jan de Groot <jgc@archlinux.org>

pkgname=gnome-panel
pkgver=3.46.0
pkgrel=1
pkgdesc='Panel of GNOME Flashback'
arch=('x86_64')
url='https://wiki.gnome.org/Projects/GnomePanel'
license=('GPL')
depends=('evolution-data-server' 'gnome-desktop' 'gnome-menus' 'libgdm' 'libwnck3' 'nautilus'
         'geocode-glib' 'polkit')
makedepends=('itstool')
optdepends=('alacarte: Main menu editor'
            'gnome-applets: Extra applets for the panel')
source=("https://download.gnome.org/sources/$pkgname/${pkgver%.*}/$pkgname-$pkgver.tar.xz")
sha256sums=('cec7a11b70c524b5e8d76d4d7e4d835ee607abda2eb42f4df7619e62eb06aeb1')

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
