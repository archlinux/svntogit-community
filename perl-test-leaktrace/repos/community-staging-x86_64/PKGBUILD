# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: John D Jones III <j[nospace]n[nospace]b[nospace]e[nospace]k[nospace]1972 -_AT_- the domain name google offers a mail service at ending in dot com>
# Generator  : CPANPLUS::Dist::Arch 1.25

pkgname=perl-test-leaktrace
pkgver=0.17
pkgrel=3
pkgdesc="Traces memory leaks"
arch=('x86_64')
license=('PerlArtistic' 'GPL')
options=('!emptydirs')
depends=('perl')
url='https://search.cpan.org/dist/Test-LeakTrace'
source=("https://search.cpan.org/CPAN/authors/id/L/LE/LEEJO/Test-LeakTrace-$pkgver.tar.gz")
sha512sums=('57ffd8c64ef871427c04419bda239d73e169f3b6ee268e0d4d7a27942c277d4b1f502e82e2e0df415b1050c0aa11944c2c3acb2e9b353855f77c91d1dfcaf00d')
_distdir="Test-LeakTrace-$pkgver"

build() {
  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""                 \
      PERL_AUTOINSTALL=--skipdeps                            \
      PERL_MM_OPT="INSTALLDIRS=vendor DESTDIR='$pkgdir'"     \
      PERL_MB_OPT="--installdirs vendor --destdir '$pkgdir'" \
      PERL_USE_UNSAFE_INC=1 \
      MODULEBUILDRC=/dev/null

    cd "$srcdir/$_distdir"
    /usr/bin/perl Makefile.PL
    make
  )
}

check() {
  cd "$srcdir/$_distdir"
  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""
    make test
  )
}

package() {
  cd "$srcdir/$_distdir"
  make install

  find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
}

# Local Variables:
# mode: shell-script
# sh-basic-offset: 2
# End:
# vim:set ts=2 sw=2 et:
