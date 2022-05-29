# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Florian Pritz <bluewind@xinu.at>

pkgname=perl-archive-extract
pkgver=0.88
pkgrel=3
pkgdesc='Generic archive extracting mechanism'
arch=(any)
license=(PerlArtistic GPL)
options=(!emptydirs)
depends=(perl)
url=https://metacpan.org/release/Archive-Extract
source=("https://search.cpan.org/CPAN/authors/id/B/BI/BINGOS/Archive-Extract-$pkgver.tar.gz")
sha512sums=('6fcb6a49e59fac5340663e5d906978af390f4ba66da6c4f02e6b2db666da68440af59ec93a687d13316089b07237b2213df55d8ebb940c4fa9eadd09d1bacc86')
_ddir="Archive-Extract-$pkgver"

build() (
  cd "$srcdir/$_ddir"
  export PERL_MM_USE_DEFAULT=1 PERL_AUTOINSTALL=--skipdeps
  unset PERL5LIB PERL_MM_OPT
  /usr/bin/perl Makefile.PL
  make
)

check() (
  cd "$srcdir/$_ddir"
  export PERL_MM_USE_DEFAULT=1
  unset PERL5LIB
  make test
)

package() (
  cd "$srcdir/$_ddir"
  make install INSTALLDIRS=vendor DESTDIR="$pkgdir"
  find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
)

# Local Variables:
# mode: shell-script
# sh-basic-offset: 2
# End:
# vim:set ts=2 sw=2 et:
