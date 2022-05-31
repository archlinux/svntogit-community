# Maintainer: Sergej Pupykin <arch+pub@sergej.pp.ru>
# Contributor: John D Jones III AKA jnbek <jnbek1972 -_AT_- g m a i l -_Dot_- com>
# Generator  : CPANPLUS::Dist::Arch 1.32

pkgname='perl-pegex'
pkgver=0.75
pkgrel=3
pkgdesc="Acmeist PEG Parser Framework"
arch=('any')
license=('PerlArtistic' 'GPL')
options=('!emptydirs')
depends=('perl-yaml-libyaml' 'perl-file-sharedir-install' 'perl-yaml-pp')
makedepends=()
url='https://metacpan.org/release/Pegex'
source=("https://search.cpan.org/CPAN/authors/id/I/IN/INGY/Pegex-$pkgver.tar.gz")
sha256sums=('4dc8d335de80b25247cdb3f946f0d10d9ba0b3c34b0ed7d00316fd068fd05edc')

build() {
  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""                 \
      PERL_AUTOINSTALL=--skipdeps                            \
      PERL_MM_OPT="INSTALLDIRS=vendor DESTDIR='"$pkgdir"'"     \
      PERL_MB_OPT="--installdirs vendor --destdir '"$pkgdir"'" \
      MODULEBUILDRC=/dev/null
    cd "$srcdir/Pegex-$pkgver"
    /usr/bin/perl Makefile.PL
    make
  )
}

check() {
  cd "$srcdir/Pegex-$pkgver"
  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""
    make test
  )
}

package() {
  cd "$srcdir/Pegex-$pkgver"
  make install
  find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
}
