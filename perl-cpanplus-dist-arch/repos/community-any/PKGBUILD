# Maintainer : Justin "juster" Davis <jrcd83@gmail.com>
# Generator  : pbjam 0.01

pkgname=perl-cpanplus-dist-arch
pkgver=1.19
pkgrel=1
pkgdesc="CPANPLUS backend for building Archlinux pacman packages"
arch=(any)
license=(PerlArtistic GPL)
depends=('perl')
url=http://search.cpan.org/dist/CPANPLUS-Dist-Arch
source=(http://search.cpan.org/CPAN/authors/id/J/JU/JUSTER/CPANPLUS-Dist-Arch-${pkgver}.tar.gz)
md5sums=('6bb154b435128f37c35b6980e6858189')
sha512sums=('63b9ac5342bd7f74c9c80e9eaa60749a8540472691a8ead1941160a7387761b5e79340ef40dd23dcda4b2e142b97e582a2f8362b0fab05f759a5109b3d7db379')
_distdir="$srcdir/CPANPLUS-Dist-Arch-${pkgver}"

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
