# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>
# Contributo: Christoph Gysin <christoph.gysin@gmail.com>

pkgname=pasystray
pkgver=0.8.2
pkgrel=1
pkgdesc='PulseAudio system tray (a replacement for padevchooser)'
arch=('x86_64')
url="https://github.com/christophgysin/pasystray"
license=('LGPL')
depends=('libpulse' 'libnotify' 'avahi' 'libx11' 'gtk3')
optdepends=('pulseaudio: To control a local pulseaudio instance'
            'pavucontrol: Launch PulseAudio mixer from tray icon'
            'paprefs: Launch PulseAudio preferences from tray icon')
source=("$pkgname-$pkgver.tar.gz::$url/archive/$pkgver.tar.gz")
sha512sums=('a4c2c257678c161ed2daf53249bc4acf50002cd8485ce031fe98d20540ec684011651fc0e5e66cd925131629630371a834660b0da69c53dbd14521ed268d13ef')

build() {
  cd $pkgname-$pkgver

  autoreconf -vif
  ./configure \
        --prefix=/usr \
        --sysconfdir=/etc

  make
}

package() {
  cd $pkgname-$pkgver

  make DESTDIR="$pkgdir" install
}

