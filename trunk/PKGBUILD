# $Id$
# Maintainer: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: shahid <helllamer@gmail.com>

pkgbase=bitcoin
pkgname=('bitcoin-daemon' 'bitcoin-qt')
pkgver=0.9.2
pkgrel=1
arch=('i686' 'x86_64')
url="http://www.bitcoin.org/"
makedepends=('boost' 'automoc4' 'qrencode' 'miniupnpc' 'protobuf')
license=('MIT')
source=(http://bitcoin.org/bin/$pkgver/bitcoin-$pkgver-linux.tar.gz
	https://raw.github.com/bitcoin/bitcoin/v$pkgver/contrib/debian/bitcoin-qt.desktop
	https://raw.github.com/bitcoin/bitcoin/v$pkgver/share/pixmaps/bitcoin128.png
	https://raw.github.com/bitcoin/bitcoin/v$pkgver/contrib/debian/examples/bitcoin.conf
	https://raw.github.com/bitcoin/bitcoin/v$pkgver/contrib/debian/manpages/bitcoind.1
	https://raw.github.com/bitcoin/bitcoin/v$pkgver/contrib/debian/manpages/bitcoin.conf.5)
sha256sums=('58a77aeb4c81b54d3903d85abce4f0fb580694a3611a415c5fe69a27dea5935b'
            'b65b377c0d9ecae9eea722843bca0add6bdb7e50929a7e1f751b79b6621c6073'
            'ad880c8459ecfdb96abe6a4689af06bdd27906e0edcd39d0915482f2da91e722'
            'e141088b07641e4e58cc750f93bbdda1ca0e8f07262fce66b73524c1ed97480e'
            '881dcc53ebe2d2a4f8647eb206fd355c69e4186f225e2dcfce19d276381e613a'
            'b7b232079027c41061dcfd21bca2054e349e4bed4f233733406bb3d90bd533ec')

prepare() {
  cd "$srcdir/$pkgbase-$pkgver-linux/src"
  tar xf $pkgbase-$pkgver.tar.gz
}

build() {
  cd "$srcdir/$pkgbase-$pkgver-linux/src/$pkgbase-$pkgver"
  ./configure --prefix=/usr --with-incompatible-bdb --with-gui=qt4
  make
}

package_bitcoin-qt() {
  pkgdesc="Bitcoin is a peer-to-peer network based digital currency - Qt"
  depends=(boost-libs qt4 miniupnpc qrencode protobuf)
  install=bitcoin-qt.install

  cd "$srcdir/$pkgbase-$pkgver-linux/src/$pkgbase-$pkgver"
  install -Dm755 src/qt/bitcoin-qt "$pkgdir"/usr/bin/bitcoin-qt
  install -Dm644 "$srcdir"/bitcoin-qt.desktop \
    "$pkgdir"/usr/share/applications/bitcoin.desktop
  install -Dm644 "$srcdir"/bitcoin128.png \
    "$pkgdir"/usr/share/pixmaps/bitcoin128.png

  install -Dm644 COPYING "$pkgdir/usr/share/licenses/$pkgname/COPYING"
}

package_bitcoin-daemon() {
  pkgdesc="Bitcoin is a peer-to-peer network based digital currency - daemon"
  depends=(boost-libs miniupnpc openssl)

  cd "$srcdir/$pkgbase-$pkgver-linux/src/$pkgbase-$pkgver"
  install -Dm755 src/bitcoind "$pkgdir"/usr/bin/bitcoind
  install -Dm644 "$srcdir"/bitcoin.conf \
    "$pkgdir/usr/share/doc/$pkgname/examples/bitcoin.conf"
  install -Dm644 "$srcdir"/bitcoind.1 \
    "$pkgdir"/usr/share/man/man1/bitcoind.1
  install -Dm644 "$srcdir"/bitcoin.conf.5 \
    "$pkgdir"/usr/share/man/man5/bitcoin.conf.5
  install -Dm644 COPYING "$pkgdir/usr/share/licenses/$pkgname/COPYING"
}

