# Maintainer: Balló György <ballogyor+arch at gmail dot com>
# Contributor: Bartłomiej Piotrowski <nospam@bpiotrowski.pl>

pkgname=lxappearance-obconf
pkgver=0.2.3
pkgrel=3
pkgdesc='Plugin for LXAppearance to configure Openbox'
arch=('x86_64')
license=('GPL2')
url='https://lxde.org/'
groups=('lxde')
depends=('lxappearance' 'openbox' 'libobrender.so')
makedepends=('intltool')
source=(https://downloads.sourceforge.net/lxde/$pkgname-$pkgver.tar.xz)
md5sums=('ae0076d489aa786f5d573f7ff592a4ab')

build() {
  cd $pkgname-$pkgver
  ./configure --prefix=/usr

  #https://bugzilla.gnome.org/show_bug.cgi?id=656231
  sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool

  make
}

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
