# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Maintainer: PyroPeter <abi1789@googlemail.com>
# Contributor: BlackEagle <ike.devolder@scarlet.be>
# Contributor: chochem <chochem@gmail.com>

pkgname=xmlstarlet
pkgver=1.6.1
pkgrel=3
pkgdesc="A set of tools to transform, query, validate, and edit XML documents"
arch=('x86_64')
url="http://xmlstar.sourceforge.net/"
license=('MIT')
depends=('libxslt')
makedepends=('fop' 'ghostscript')
options=('docs')
source=("xmlstarlet-$pkgver.tar.gz::http://sourceforge.net/projects/xmlstar/files/xmlstarlet/$pkgver/xmlstarlet-$pkgver.tar.gz/download")
sha512sums=('4228df812caec7059d7a76986c4d9a4262bd861cc53dca05f341ae6c062be05f1c39fc637918ab00f60f40587c6c556e3c9bfaf8a18b149e3c321a92214dbe8b')

build() {
  cd "$srcdir/$pkgname-$pkgver"
  LIBXSLT_PREFIX=/usr LIBXML_PREFIX=/usr ./configure --prefix=/usr --enable-build-docs
  make
}

package() {
  cd "$srcdir/$pkgname-$pkgver"
  make DESTDIR="${pkgdir}" install
  install -Dm0644 Copyright "$pkgdir"/usr/share/licenses/$pkgname/COPYING
  ln -s xml "$pkgdir"/usr/bin/xmlstarlet
}
