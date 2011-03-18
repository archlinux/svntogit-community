# Maintainer: Kyle Keen <keenerd@gmail.com>
pkgname=pacgraph
pkgver=20110317
pkgrel=1
pkgdesc="Draws a graph of installed packages to PNG/SVG/GUI/console.  Good for finding bloat."
arch=('any')
url="http://kmkeen.com/pacgraph/"
license=('GPL')
depends=('python')
makedepends=()
optdepends=('inkscape: png backend'
            'imagemagick: png backend'
            'svg2png: png backend'
            'tk: gui version')
source=(http://kmkeen.com/pacgraph/$pkgname-$pkgver.tar.gz)
md5sums=('659db0e796a43209181fbebe2f657e15')

build() {
  cd "$srcdir/$pkgname"
  install -D -m 0755 pacgraph    "$pkgdir/usr/bin/pacgraph"
  install -D -m 0755 pacgraph-tk "$pkgdir/usr/bin/pacgraph-tk"
  install -Dm644     $pkgname.1  "$pkgdir/usr/share/man/man1/$pkgname.1"
}

