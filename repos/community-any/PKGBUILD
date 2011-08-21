# Maintainer : Justin "juster" Davis <jrcd83@gmail.com>
# Generator  : pbjam 0.01

pkgname=perl-cpanplus-dist-arch
pkgver=1.18
pkgrel=1
pkgdesc="CPANPLUS backend for building Archlinux pacman packages"
arch=(any)
license=(PerlArtistic GPL)
depends=('perl')
url=http://search.cpan.org/dist/CPANPLUS-Dist-Arch
source=(http://search.cpan.org/CPAN/authors/id/J/JU/JUSTER/CPANPLUS-Dist-Arch-1.18.tar.gz)
md5sums=(0bb9183ea50c3e8d6f1903ba2016bc65)
sha512sums=(77760064154561f568e4fd02585b66b2f634a597b8366eba1a12e75de7d6c6fada82321b638308ad5910b10557cd7c404037e09d35747576e923baa8c51125ad)
_distdir="$srcdir/CPANPLUS-Dist-Arch-1.18"

build() {
  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""                 \
      PERL_AUTOINSTALL=--skipdeps                            \
      PERL_MM_OPT="INSTALLDIRS=vendor DESTDIR='$pkgdir'"     \
      PERL_MB_OPT="--installdirs vendor --destdir '$pkgdir'" \
      MODULEBUILDRC=/dev/null

    cd "$_distdir"
    /usr/bin/perl Build.PL
    ./Build
  )
}

check() {
  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""
    cd "$_distdir"
    ./Build test
  )
}

package() {
    cd "$_distdir"
    ./Build install
    find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
}

# Local Variables:
# mode: shell-script
# sh-basic-offset: 2
# End:
# vim:set ts=2 sw=2 et:
