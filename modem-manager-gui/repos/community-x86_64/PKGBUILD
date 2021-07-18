# Maintainer: Balló György <ballogyor+arch at gmail dot com>
# Contributor: Ilya Medvedev <medved55rus [at] gmail [dot] com>

pkgname=modem-manager-gui
pkgver=0.0.20
pkgrel=2
pkgdesc='Frontend for ModemManager daemon able to control specific modem functions'
arch=('x86_64')
url='https://linuxonly.ru/page/modem-manager-gui'
license=('GPL3')
depends=('gdbm' 'gtk3' 'gtkspell3' 'libnotify' 'modemmanager')
makedepends=('po4a' 'itstool')
optdepends=('networkmanager: monitor network traffic')
options=('!emptydirs')
source=("https://download.tuxfamily.org/gsf/source/$pkgname-$pkgver.tar.gz")
sha256sums=('00c7054293e5e7832a7eeb7d9ba0d35745e95d2f7df27ab8f912302e2bb56fc5')

prepare() {
  cd $pkgname
  sed -i 's/gzip /gzip -n /' man/Makefile
}

build() {
  cd $pkgname
  ./configure --prefix=/usr
  make
}
 
package() {
  cd $pkgname
  make DESTDIR="$pkgdir" install
}
