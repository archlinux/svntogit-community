pkgname=perl-sub-quote
epoch=1
pkgver=2.006008
pkgrel=1
pkgdesc="efficient generation of subroutines via string eval"
arch=('any')
license=('PerlArtistic' 'GPL')
options=('!emptydirs')
depends=('perl')
makedepends=('perl-test-fatal>=0.010')
url='https://search.cpan.org/dist/Sub-Quote'
source=("https://search.cpan.org/CPAN/authors/id/H/HA/HAARG/Sub-Quote-$pkgver.tar.gz")
sha256sums=('94bebd500af55762e83ea2f2bc594d87af828072370c7110c60c238a800d15b2')

build() {
  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""                 \
      PERL_AUTOINSTALL=--skipdeps                            \
      PERL_MM_OPT="INSTALLDIRS=vendor DESTDIR='$pkgdir'"     \
      PERL_MB_OPT="--installdirs vendor --destdir '$pkgdir'" \
      MODULEBUILDRC=/dev/null

    cd "$srcdir/Sub-Quote-$pkgver"
    perl Makefile.PL
    make
  )
}

check() {
  cd "$srcdir/Sub-Quote-$pkgver"
  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""
    make test
  )
}

package() {
  cd "$srcdir/Sub-Quote-$pkgver"
  make install

  find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
}
