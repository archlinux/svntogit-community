# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>

pkgname=perl-tree-dag-node
pkgver=1.32
pkgrel=1
pkgdesc="base class for trees"
arch=('any')
url="https://search.cpan.org/dist/Tree-DAG_Node"
license=('GPL' 'PerlArtistic')
depends=('perl-file-slurp-tiny')
options=('!emptydirs')
source=(https://www.cpan.org/authors/id/R/RS/RSAVAGE/Tree-DAG_Node-$pkgver.tgz)
sha512sums=('3ab6b48495abd09643555cf0160d00db39dc7ce576299b24eb4bc39e799ba478d88f863d8b2ec95853dc173e97c6efc3faff14e1d7c080f5166150f6fce2f817')

build() {
  cd  "$srcdir"/Tree-DAG_Node-$pkgver
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

package() {
  cd  "$srcdir"/Tree-DAG_Node-$pkgver
  make install DESTDIR="$pkgdir"
  find "$pkgdir" -name '.packlist' -delete
  find "$pkgdir" -name '*.pod' -delete
}
