# $Id$
# Maintainer: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: shahid <helllamer@gmail.com>

pkgbase=bitcoin
pkgname=('bitcoin-daemon' 'bitcoin-cli' 'bitcoin-qt')
pkgver=0.11.0
pkgrel=3
arch=('i686' 'x86_64')
url="http://www.bitcoin.org/"
makedepends=('boost' 'automoc4' 'qrencode' 'miniupnpc' 'protobuf')
license=('MIT')
source=(http://bitcoin.org/bin/bitcoin-core-$pkgver/bitcoin-$pkgver.tar.gz
	https://raw.github.com/bitcoin/bitcoin/v$pkgver/contrib/debian/bitcoin-qt.desktop
	https://raw.github.com/bitcoin/bitcoin/v$pkgver/share/pixmaps/bitcoin128.png
	https://raw.github.com/bitcoin/bitcoin/v$pkgver/contrib/debian/examples/bitcoin.conf
	https://raw.github.com/bitcoin/bitcoin/v$pkgver/contrib/debian/manpages/bitcoind.1
	https://raw.github.com/bitcoin/bitcoin/v$pkgver/contrib/debian/manpages/bitcoin.conf.5
	https://github.com/bitcoin/bitcoin/commit/9f3e48e5219a09b5ddfd6883d1f0498910eff4b6.patch)
sha256sums=('51ba1756addfa71567559e3f22331c1d908a63571891287689fff7113035d09f'
            'b65b377c0d9ecae9eea722843bca0add6bdb7e50929a7e1f751b79b6621c6073'
            'ad880c8459ecfdb96abe6a4689af06bdd27906e0edcd39d0915482f2da91e722'
            '7b9001258d0781b8ae6fba31b7fb99d8009af8cda5a005f4854aa8b20f55b214'
            '829d5d38c8c3145b6debcb569bfa75acdfcfab5d914495b56ceb4d02060f130f'
            '9acf7f46052f6e508af4f38be4574f34bf0f57d2cf462f072606d3f177b4c957'
            '0910004577764c2251a33c4868c7358a42da68f94d6462e44bbcb1945cefd748')

# Upstream should be more coherent!
case "$pkgver" in
*.*.*.*)
  _pkgver=${pkgver%.*}
  ;;
*)
  _pkgver=$pkgver
  ;;
esac

prepare() {
  cd "$pkgbase-$pkgver"
  patch -Np1 -i "$srcdir"/9f3e48e5219a09b5ddfd6883d1f0498910eff4b6.patch
}

build() {
  cd "$srcdir/$pkgbase-$pkgver"
  CXXFLAGS="$CXXFLAGS -DBOOST_VARIANT_USE_RELAXED_GET_BY_DEFAULT=1 -UUPNPDISCOVER_SUCCESS"
  ./configure --prefix=/usr --with-incompatible-bdb --with-gui=qt4
  make
}

package_bitcoin-qt() {
  pkgdesc="Bitcoin is a peer-to-peer network based digital currency - Qt"
  depends=(boost-libs qt4 miniupnpc qrencode protobuf)
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
  depends=(boost-libs miniupnpc openssl)

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
  depends=(boost-libs openssl)

  cd "$pkgbase-$pkgver"
  install -Dm755 src/bitcoin-cli "$pkgdir"/usr/bin/bitcoin-cli
  install -Dm644 COPYING "$pkgdir/usr/share/licenses/$pkgname/COPYING"
}
