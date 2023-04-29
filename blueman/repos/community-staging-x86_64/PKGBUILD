# Maintainer: Balló György <ballogyor+arch at gmail dot com>
# Contributor: Arthur Zamarin <arthurzam@gmail.com>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=blueman
pkgver=2.3.5
pkgrel=2
pkgdesc="GTK+ Bluetooth Manager"
arch=('x86_64')
url="https://github.com/blueman-project/blueman"
license=('GPL')
depends=('bluez' 'bluez-libs' 'gtk3' 'libnm' 'python-cairo' 'python-gobject')
makedepends=('cython' 'intltool' 'iproute2')
optdepends=('dnsmasq: Network Access Point (NAP) support'
            'iproute2: Network Access Point (NAP) support'
            'networkmanager: Dial Up Networking (DUN) and Personal Area Networking (PAN) support'
            'pulseaudio-bluetooth: audio devices support')
source=(https://github.com/blueman-project/$pkgname/releases/download/$pkgver/$pkgname-$pkgver.tar.xz)
sha256sums=('b2d21afdf77a06cd86daf5402406f7d2a53459817e29e0bebc4911d4f0dcfda1')

prepare() {
  cd $pkgname-$pkgver

  # Use correct D-Bus config location
  sed -i '/^dbusdir =/ s/sysconfdir/datadir/' data/configs/Makefile.{am,in}
}

build() {
  cd $pkgname-$pkgver
  ./configure \
    --prefix=/usr \
    --sysconfdir=/etc \
    --libexecdir=/usr/lib/$pkgname \
    --disable-schemas-compile \
    --with-dhcp-config='/etc/dhcpd.conf'
  make
}

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
  install -d -o root -g 102 -m 750 "$pkgdir/usr/share/polkit-1/rules.d"
}
