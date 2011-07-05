# Maintainer: Florian Pritz <bluewind@xinu.at>
# Contributor: Justin Davis <jrcd83@gmail.com>
# Generator  : CPANPLUS::Dist::Arch 1.12

pkgname='perl-cpanplus-dist-arch'
pkgver='1.13'
pkgrel='1'
pkgdesc="CPANPLUS backend for building Archlinux pacman packages"
arch=('any')
license=('PerlArtistic' 'GPL')
options=('!emptydirs')
depends=('perl')
makedepends=()
url='http://search.cpan.org/dist/CPANPLUS-Dist-Arch'
source=('http://search.cpan.org/CPAN/authors/id/J/JU/JUSTER/CPANPLUS-Dist-Arch-1.13.tar.gz')
md5sums=('a1634ec1d8cea872e3a6b2220c57c0f4')
_distdir="${srcdir}/CPANPLUS-Dist-Arch-1.13"

build() {
  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""                 \
      PERL_AUTOINSTALL=--skipdeps                            \
      PERL_MM_OPT="INSTALLDIRS=vendor DESTDIR='$pkgdir'"     \
      PERL_MB_OPT="--installdirs vendor --destdir '$pkgdir'" \
      MODULEBUILDRC=/dev/null

    cd "$_distdir"
    /usr/bin/perl Makefile.PL
    make
  )
}

check() {
  cd "$_distdir"
  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""
    make test
  )
}

package() {
  cd "$_distdir"
  make install
  find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
}

# Local Variables:
# mode: shell-script
# sh-basic-offset: 2
# End:
# vim:set ts=2 sw=2 et:
