# Maintainer: Balló György <ballogyor+arch at gmail dot com>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: Juergen Hoetzel <juergen@archlinux.org>

pkgname=lxpanel
pkgver=0.10.1
pkgrel=1
pkgdesc='Lightweight X11 desktop panel for LXDE'
arch=('x86_64')
license=('GPL2')
url='https://lxde.org/'
groups=('lxde')
depends=('alsa-lib' 'curl' 'menu-cache' 'lxmenu-data' 'libwnck' 'libfm-gtk2' 'libkeybinder2')
makedepends=('intltool' 'docbook-xml' 'docbook-xsl' 'wireless_tools')
optdepends=('wireless_tools: netstat plugin')
source=(https://downloads.sourceforge.net/lxde/$pkgname-$pkgver.tar.xz)
sha256sums=('1e318f57d7e36b61c23a504d03d2430c78dad142c1804451061f1b3ea5441ee8')

build() {
  cd $pkgname-$pkgver
  ./configure \
    --sysconfdir=/etc \
    --prefix=/usr

  #https://bugzilla.gnome.org/show_bug.cgi?id=656231
  sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool

  make
}

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
