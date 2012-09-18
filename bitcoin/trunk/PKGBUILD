# $Id$
# Maintainer: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: shahid <helllamer@gmail.com>

pkgbase=bitcoin
pkgname=('bitcoin-daemon' 'bitcoin-qt')
pkgver=0.7.0
pkgrel=1
arch=('i686' 'x86_64')
url="http://www.bitcoin.org/"
makedepends=('boost' 'automoc4' 'miniupnpc')
conflicts=('bitcoin' 'bitcoin-bin' 'bitcoin-git')
replaces=('bitcoin' 'bitcoin-bin' 'bitcoin-git')
license=('MIT')
source=(http://sourceforge.net/projects/bitcoin/files/Bitcoin/bitcoin-$pkgver/bitcoin-$pkgver-linux.tar.gz)
sha256sums=('4b7a44fec28cbd9194a1303dd65bba8f13aa2facd4e06e4a3d1df6d66bc1deb5')

build() {
  cd "$srcdir/$pkgbase-$pkgver-linux/src"

  # and make qt gui
  qmake
  make

  # make bitcoind
  make -f makefile.unix -C src  CXXFLAGS="$CXXFLAGS" USE_UPNP=1
}


package_bitcoin-qt() {
  pkgdesc="Bitcoin is a peer-to-peer network based digital currency - QT"
  depends=(boost-libs qt miniupnpc)
  install=bitcoin-qt.install

  cd "$srcdir/$pkgbase-$pkgver-linux/src"
  install -Dm755 bitcoin-qt "$pkgdir"/usr/bin/bitcoin-qt
  install -Dm644 contrib/debian/bitcoin-qt.desktop \
    "$pkgdir"/usr/share/applications/bitcoin.desktop
  install -Dm644 share/pixmaps/bitcoin80.xpm \
    "$pkgdir"/usr/share/pixmaps/bitcoin80.xpm

  install -Dm644 COPYING "$pkgdir/usr/share/licenses/$pkgname/COPYING"
}

package_bitcoin-daemon() {
  pkgdesc="Bitcoin is a peer-to-peer network based digital currency - daemon"
  depends=(boost-libs miniupnpc openssl)

  cd "$srcdir/$pkgbase-$pkgver-linux/src"
  install -Dm755 src/bitcoind "$pkgdir"/usr/bin/bitcoind
  install -Dm644 contrib/debian/examples/bitcoin.conf \
    "$pkgdir/usr/share/doc/$pkgname/examples/bitcoin.conf"
  install -Dm644 contrib/debian/manpages/bitcoind.1 \
    "$pkgdir"/usr/share/man/man1/bitcoind.1
  install -Dm644 contrib/debian/manpages/bitcoin.conf.5 \
    "$pkgdir"/usr/share/man/man5/bitcoin.conf.5
  install -Dm644 COPYING "$pkgdir/usr/share/licenses/$pkgname/COPYING"
}

