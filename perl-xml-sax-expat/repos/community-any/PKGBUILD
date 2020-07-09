# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Francois Charette <firmicus@gmx.net>

pkgname=perl-xml-sax-expat
pkgver=0.51
pkgrel=7
pkgdesc="SAX2 Driver for Expat (XML::Parser) "
arch=('any')
url="https://search.cpan.org/dist/XML-SAX-Expat"
license=('GPL' 'PerlArtistic')
depends=('perl-xml-namespacesupport' 'perl-xml-parser' 'perl-xml-sax')
install=perl-xml-sax-expat.install
options=('!emptydirs')
source=(https://www.cpan.org/authors/id/B/BJ/BJOERN/XML-SAX-Expat-$pkgver.tar.gz)
sha256sums=('4c016213d0ce7db2c494e30086b59917b302db8c292dcd21f39deebd9780c83f')

build() {
  cd  "$srcdir"/XML-SAX-Expat-$pkgver
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor 
  make 
}
package(){
  cd  "$srcdir"/XML-SAX-Expat-$pkgver
  make pure_install doc_install DESTDIR="$pkgdir" 
  find "$pkgdir" -name '.packlist' -delete
  find "$pkgdir" -name '*.pod' -delete
}
