# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Florian Pritz <bluewind@xinu.at>

pkgname=perl-term-ui
pkgver=0.50
pkgrel=2
pkgdesc='User interfaces via Term::ReadLine made easy'
arch=('any')
license=('PerlArtistic' 'GPL')
options=("!emptydirs")
depends=('perl-log-message' 'perl-log-message-simple')
url='https://metacpan.org/release/Term-UI'
source=("https://search.cpan.org/CPAN/authors/id/B/BI/BINGOS/Term-UI-$pkgver.tar.gz")
sha512sums=('338f564a5405804d3f34840dbd26309911b0dfa6de346fc11c0fb4e33e0e2d42915a26b3f9569ccf95333a8cf20bded9830c923c69df48aa72670cdabe05fc98')
_ddir="Term-UI-$pkgver"

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
  #find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
)

# Local Variables:
# mode: shell-script
# sh-basic-offset: 2
# End:
# vim:set ts=2 sw=2 et:
