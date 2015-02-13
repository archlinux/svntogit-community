# Contributor: John D Jones III <jnbek1972 -_AT_- g m a i l -_Dot_- com>
# Generator  : CPANPLUS::Dist::Arch 1.28

pkgname='perl-test-warnings'
pkgver='0.016'
pkgrel='1'
pkgdesc="Test for warnings and the lack of them"
arch=('any')
license=('PerlArtistic' 'GPL')
options=('!emptydirs')
depends=('perl')
makedepends=()
url='http://search.mcpan.org/dist/Test-Warnings'
source=('http://search.mcpan.org/CPAN/authors/id/E/ET/ETHER/Test-Warnings-0.016.tar.gz')
md5sums=('5608b3f8dbdd65d0251200754d97863a')
sha512sums=('78a3e26d2093be8612e1e97f2d45023f224ea7e09f9d669a049fd331e7ff49fb93be52996d7f7fba29263437307587fedd80c54a56b6b282b328668152557027')
_distdir="Test-Warnings-0.016"

build() {
  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""                 \
      PERL_AUTOINSTALL=--skipdeps                            \
      PERL_MM_OPT="INSTALLDIRS=vendor DESTDIR='$pkgdir'"     \
      PERL_MB_OPT="--installdirs vendor --destdir '$pkgdir'" \
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
