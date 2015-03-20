# Maintainer: Florian Pritz <bluewind@xinu.at>

pkgname=perl-cpanplus-dist-arch
pkgver=1.30
pkgrel=1
pkgdesc='CPANPLUS backend for building ArchLinux pacman packages'
arch=(any)
license=(PerlArtistic GPL)
options=(!emptydirs)
depends=(perl perl-cpanplus)
url=https://metacpan.org/release/CPANPLUS-Dist-Arch
source=("http://search.cpan.org/CPAN/authors/id/J/JU/JUSTER/CPANPLUS-Dist-Arch-$pkgver.tar.gz")
md5sums=(9335f2404c80692c7ffc859e5d648658)
sha512sums=(1210fc64f1cb228edd94220f8116f7e8294146bc763b6e18ea5271f1bc18eb48169026b94ee0fa39ff6d8bd66e034882bd7d3a3ea1c34861f1ab434df11a70ff)
_ddir="CPANPLUS-Dist-Arch-$pkgver"

build()
(
  cd "$srcdir/$_ddir"
  export PERL_MM_USE_DEFAULT=1 PERL_AUTOINSTALL=--skipdeps
  unset PERL5LIB PERL_MM_OPT
  /usr/bin/perl Makefile.PL
  make
)

check()
(
  cd "$srcdir/$_ddir"
  export PERL_MM_USE_DEFAULT=1
  unset PERL5LIB
  make test
)

package()
(
  cd "$srcdir/$_ddir"
  make install INSTALLDIRS=vendor DESTDIR="$pkgdir"
  find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
)

# Local Variables:
# mode: shell-script
# sh-basic-offset: 2
# End:
# vim:set ts=2 sw=2 et:
