# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Alessio 'mOLOk' Bolognino <themolok@gmail.com>

pkgname=docbook2x
pkgver=0.8.8
pkgrel=18
pkgdesc="A software package that converts DocBook documents into the traditional Unix man page format and the GNU Texinfo format."
arch=('x86_64')
url="http://docbook2x.sourceforge.net"
license=("MIT")
depends=('glibc' 'perl-sgmls' 'perl-xml-parser' 'perl-xml-sax' 'libxslt'
	 'jade' 'perl-xml-sax-expat')
makedepends=('texinfo')
source=(https://downloads.sourceforge.net/$pkgname/docbook2X-$pkgver.tar.gz
        datadir.diff)
md5sums=('b9b76a6af198c4f44574cfd17a322f01'
         '826fae88a435d9278c4f9614991d55a1')

prepare() {
  cd "$srcdir"/docbook2X-$pkgver
  patch -p1 <"$srcdir"/datadir.diff
  sed -e 's/AM_CONFIG_HEADER(/AC_CONFIG_HEADERS(/' -i configure.ac
  autoreconf -vfi
}

build()  {
  cd docbook2X-$pkgver
  # to avoid file conflicts with docbook2* from docbook-utils
  ./configure \
    --prefix=/usr \
    --mandir=/usr/share/man \
    --program-transform-name 's,docbook2,db2x_docbook2,'
  make
}

package() {
  cd docbook2X-$pkgver
  make DESTDIR="$pkgdir" install
  install -D -m0644 COPYING "$pkgdir"/usr/share/licenses/$pkgname/license
  sed -i 's|http://docbook2x.sf.net/latest|/usr/share/docbook2X|g' \
    "$pkgdir"/usr/bin/db2x_xsltproc
}
