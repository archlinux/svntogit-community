# $Id$
# Maintainer: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: shahid <helllamer@gmail.com>

pkgbase=bitcoin
pkgname=('bitcoin-daemon' 'bitcoin-cli' 'bitcoin-qt')
pkgver=0.9.3
pkgrel=4
arch=('i686' 'x86_64')
url="http://www.bitcoin.org/"
makedepends=('boost' 'automoc4' 'qrencode' 'miniupnpc' 'protobuf')
license=('MIT')
source=(http://bitcoin.org/bin/$pkgver/bitcoin-$pkgver-linux.tar.gz
	https://github.com/bitcoin/bitcoin/commit/0a94661e8db94e84ecbf1ea45a51fb3c7fb77283.patch
	https://github.com/bitcoin/bitcoin/commit/b8e81b7ccd4490155e3345fc73346ff8c3a77524.patch
	https://github.com/bitcoin/bitcoin/commit/60c51f1c381bbd93c70cfdf41c6688609a7956fc.patch
	https://github.com/bitcoin/bitcoin/commit/037bfefe6bccbdf656e628a1f4526db8f80c3922.patch
	https://raw.github.com/bitcoin/bitcoin/v$pkgver/contrib/debian/bitcoin-qt.desktop
	https://raw.github.com/bitcoin/bitcoin/v$pkgver/share/pixmaps/bitcoin128.png
	https://raw.github.com/bitcoin/bitcoin/v$pkgver/contrib/debian/examples/bitcoin.conf
	https://raw.github.com/bitcoin/bitcoin/v$pkgver/contrib/debian/manpages/bitcoind.1
	https://raw.github.com/bitcoin/bitcoin/v$pkgver/contrib/debian/manpages/bitcoin.conf.5)
sha256sums=('c425783b6cbab9b801ad6a1dcc9235828b98e5dee6675112741f8b210e4f65cd'
            '18f5d43dd29682c8f9bd98dfb94c07b2453c99b9454996651562410b535e289b'
            'ac3a6d0e9116566f44ef99b6fc5ae7ec792a05e73d33b9db25e4f62b296b5d59'
            '67c50de4c469e40d8fb0a7663acd5af8dbbe93f362a5192e981bfa2ec9ab82df'
            '9ff94c3ddb09b0b27eda2e157627ff61808afd7a8fedc0c9d1b0db1a53ee1138'
            'b65b377c0d9ecae9eea722843bca0add6bdb7e50929a7e1f751b79b6621c6073'
            'ad880c8459ecfdb96abe6a4689af06bdd27906e0edcd39d0915482f2da91e722'
            'e141088b07641e4e58cc750f93bbdda1ca0e8f07262fce66b73524c1ed97480e'
            '881dcc53ebe2d2a4f8647eb206fd355c69e4186f225e2dcfce19d276381e613a'
            'b7b232079027c41061dcfd21bca2054e349e4bed4f233733406bb3d90bd533ec')

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
  local x
  cd "$srcdir/$pkgbase-$pkgver-linux/src"
  tar xf $pkgbase-$_pkgver.tar.gz
  cd "$pkgbase-$_pkgver"

  # Disable SSLv3 for Puddle + FS#43396
  for x in 0a94661e8db94e84ecbf1ea45a51fb3c7fb77283 b8e81b7ccd4490155e3345fc73346ff8c3a77524 \
           60c51f1c381bbd93c70cfdf41c6688609a7956fc 037bfefe6bccbdf656e628a1f4526db8f80c3922; do
    patch -Np1 -i "$srcdir/$x.patch"
  done
}

build() {
  cd "$srcdir/$pkgbase-$pkgver-linux/src/$pkgbase-$_pkgver"
  ./configure --prefix=/usr --with-incompatible-bdb --with-gui=qt4
  make
}

package_bitcoin-qt() {
  pkgdesc="Bitcoin is a peer-to-peer network based digital currency - Qt"
  depends=(boost-libs qt4 miniupnpc qrencode protobuf)
  install=bitcoin-qt.install

  cd "$srcdir/$pkgbase-$pkgver-linux/src/$pkgbase-$_pkgver"
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

  cd "$srcdir/$pkgbase-$pkgver-linux/src/$pkgbase-$_pkgver"
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

  cd "$srcdir/$pkgbase-$pkgver-linux/src/$pkgbase-$_pkgver"
  install -Dm755 src/bitcoin-cli "$pkgdir"/usr/bin/bitcoin-cli
  install -Dm644 COPYING "$pkgdir/usr/share/licenses/$pkgname/COPYING"
}
