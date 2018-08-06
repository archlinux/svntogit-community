# Maintainer: Florian Pritz <bluewind@xinu.at>

pkgname=perl-cpanplus-dist-arch
pkgver=1.32
pkgrel=4
pkgdesc='CPANPLUS backend for building ArchLinux pacman packages'
arch=(any)
license=(PerlArtistic GPL)
options=(!emptydirs)
depends=(perl perl-cpanplus)
url=https://metacpan.org/release/CPANPLUS-Dist-Arch
source=("http://search.cpan.org/CPAN/authors/id/J/JN/JNBEK/CPANPLUS-Dist-Arch-$pkgver.tar.gz")
md5sums=(673be0f0651e975faf4aa59536361d60)
sha512sums=(92aa6214c56b73c5ce48998a9cc86d619ac3e8c01c1cd3445a99fc9dbc4740923f0cc7708f7270dbc1e930cc783366f98833a8ae58a62f225b614d626c79665d)
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
