# Maintainer: Sergej Pupykin <arch+pub@sergej.pp.ru>
# Contributor: John D Jones III <jnbek1972 -_AT_- g m a i l -_Dot_- com>
# Generator  : CPANPLUS::Dist::Arch 1.28

pkgname='perl-test-warnings'
pkgver=0.031
pkgrel=3
pkgdesc="Test for warnings and the lack of them"
arch=('any')
license=('PerlArtistic' 'GPL')
options=('!emptydirs')
depends=('perl')
makedepends=()
url='https://search.mcpan.org/dist/Test-Warnings'
source=("https://search.mcpan.org/CPAN/authors/id/E/ET/ETHER/Test-Warnings-$pkgver.tar.gz")
md5sums=('f608f7011b0bb8f27d3a27e646a52f60')

build() {
  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""                 \
      PERL_AUTOINSTALL=--skipdeps                            \
      PERL_MM_OPT="INSTALLDIRS=vendor DESTDIR='"$pkgdir"'"     \
      PERL_MB_OPT="--installdirs vendor --destdir '"$pkgdir"'" \
      PERL_USE_UNSAFE_INC=1 \
      MODULEBUILDRC=/dev/null

    cd "$srcdir/Test-Warnings-$pkgver"
    /usr/bin/perl Makefile.PL
    make
  )
}

check() {
  cd "$srcdir/Test-Warnings-$pkgver"
  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""
    make test
  )
}

package() {
  cd "$srcdir/Test-Warnings-$pkgver"
  make install

  find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
}
