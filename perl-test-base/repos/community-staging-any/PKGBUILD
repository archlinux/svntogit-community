# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Francois Charette <firmicus@gmx.net>

pkgname=perl-test-base
pkgver=0.89
pkgrel=2
pkgdesc="A Data Driven Testing Framework"
arch=('any')
url="https://search.cpan.org/dist/Test-Base"
license=('GPL' 'PerlArtistic')
depends=('perl-spiffy>=0.30')
options=('!emptydirs')
source=(https://www.cpan.org/authors/id/I/IN/INGY/Test-Base-$pkgver.tar.gz)
sha256sums=('2794a1aaaeb1d3a287dd2c7286258663796562f7db9ccc6b424bc4f1de8ad014')

build() {
  cd  "$srcdir"/Test-Base-$pkgver
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

package() {
  cd  "$srcdir"/Test-Base-$pkgver
  make install DESTDIR="$pkgdir"
  find "$pkgdir" -name '.packlist' -delete
  find "$pkgdir" -name '*.pod' -delete
}
