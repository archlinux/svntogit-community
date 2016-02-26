# $Id$
# Maintainer: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: shahid <helllamer@gmail.com>

#_dbver=4.8.30
pkgbase=bitcoin
pkgname=('bitcoin-daemon' 'bitcoin-cli' 'bitcoin-qt' 'bitcoin-tx')
pkgver=0.12.0
pkgrel=2
arch=('i686' 'x86_64')
url="http://www.bitcoin.org/"
makedepends=('boost' 'libevent' 'qt5-base' 'qt5-tools' 'qrencode' 'miniupnpc' 'protobuf')
license=('MIT')
source=(http://bitcoin.org/bin/bitcoin-core-$pkgver/bitcoin-$pkgver.tar.gz
        https://raw.github.com/bitcoin/bitcoin/v$pkgver/contrib/debian/bitcoin-qt.desktop
        https://raw.github.com/bitcoin/bitcoin/v$pkgver/share/pixmaps/bitcoin128.png
        https://raw.github.com/bitcoin/bitcoin/v$pkgver/contrib/debian/examples/bitcoin.conf
        https://raw.github.com/bitcoin/bitcoin/v$pkgver/contrib/debian/manpages/bitcoind.1
        https://raw.github.com/bitcoin/bitcoin/v$pkgver/contrib/debian/manpages/bitcoin.conf.5)
#        http://download.oracle.com/berkeley-db/db-${_dbver}.NC.tar.gz
sha256sums=('0f1cda66c841a548a07cc37e80b0727354b1236d9f374c7d44362acdb85eb3e1'
            'b65b377c0d9ecae9eea722843bca0add6bdb7e50929a7e1f751b79b6621c6073'
            'ad880c8459ecfdb96abe6a4689af06bdd27906e0edcd39d0915482f2da91e722'
            'efe06ab377706338bc75fa1e24de9785950029f3350a17a4b8ce563b760f3c0c'
            '7d090ddd485c36d4fae5e6627388c5550f824fd498d5fd958ec999857fff7b28'
            '7f4021e34d52c321f679b548fcf6d55b4da30077b7aed392976f048ab88dcdd1')

# Upstream should be more coherent!
case "$pkgver" in
*.*.*.*)
  _pkgver=${pkgver%.*}
  ;;
*)
  _pkgver=$pkgver
  ;;
esac

# TODO: Build using db 4.8.30
#prepare() {
#  mkdir -p db4
#}

build() {
#  cd "db-$_dbver.NC/build_unix"
#  ../dist/configure --enable-cxx --disable-shared --with-pic --prefix="$srcdir/db4"
#  make
#  make install

  cd "$srcdir/$pkgbase-$pkgver"
  ./configure --prefix=/usr --with-gui=qt5 --with-incompatible-bdb #LDFLAGS="-L$srcdir/db4/lib/ $LDFLAGS" CPPFLAGS="-I$srcdir/db4/include/ $CPPFLAGS"
  make
}

package_bitcoin-qt() {
  pkgdesc="Bitcoin is a peer-to-peer network based digital currency - Qt"
  depends=(boost-libs desktop-file-utils libevent qt5-base miniupnpc qrencode protobuf)
  install=bitcoin-qt.install

  cd "$pkgbase-$pkgver"
  install -Dm755 src/qt/bitcoin-qt "$pkgdir"/usr/bin/bitcoin-qt
  install -Dm644 "$srcdir"/bitcoin-qt.desktop \
    "$pkgdir"/usr/share/applications/bitcoin.desktop
  install -Dm644 "$srcdir"/bitcoin128.png \
    "$pkgdir"/usr/share/pixmaps/bitcoin128.png

  install -Dm644 COPYING "$pkgdir/usr/share/licenses/$pkgname/COPYING"
}

package_bitcoin-daemon() {
  pkgdesc="Bitcoin is a peer-to-peer network based digital currency - daemon"
  depends=(boost-libs libevent miniupnpc)

  cd "$pkgbase-$pkgver"
  install -Dm755 src/bitcoind "$pkgdir"/usr/bin/bitcoind
  install -Dm644 "$srcdir"/bitcoin.conf \
    "$pkgdir/usr/share/doc/$pkgname/examples/bitcoin.conf"
  install -Dm644 "$srcdir"/bitcoind.1 \
    "$pkgdir"/usr/share/man/man1/bitcoind.1
  install -Dm644 "$srcdir"/bitcoin.conf.5 \
    "$pkgdir"/usr/share/man/man5/bitcoin.conf.5
  install -Dm644 COPYING "$pkgdir/usr/share/licenses/$pkgname/COPYING"
}

package_bitcoin-cli() {
  pkgdesc="Bitcoin is a peer-to-peer network based digital currency - RPC client"
  depends=(boost-libs libevent)

  cd "$pkgbase-$pkgver"
  install -Dm755 src/bitcoin-cli "$pkgdir"/usr/bin/bitcoin-cli
  install -Dm644 COPYING "$pkgdir/usr/share/licenses/$pkgname/COPYING"
}

package_bitcoin-tx() {
  pkgdesc="Bitcoin is a peer-to-peer network based digital currency - Transaction tool"
  depends=(boost-libs openssl)

  cd "$pkgbase-$pkgver"
  install -Dm755 src/bitcoin-tx "$pkgdir"/usr/bin/bitcoin-tx
  install -Dm644 COPYING "$pkgdir/usr/share/licenses/$pkgname/COPYING"
}

# vim:set ts=2 sw=2 et:
