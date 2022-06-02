# Maintainer: Sergej Pupykin <arch+pub@sergej.pp.ru>

pkgname='perl-mail-message'
pkgver=3.012
pkgrel=1
pkgdesc="container for MIME-encoded message information"
arch=('any')
license=('PerlArtistic' 'GPL')
options=('!emptydirs')
depends=('perl' 'perl-user-identity' 'perl-mailtools' 'perl-mime-types'
	 'perl-io-stringy' 'perl-uri')
makedepends=()
url='https://search.mcpan.org/dist/Mail-Message'
source=("https://search.cpan.org/CPAN/authors/id/M/MA/MARKOV/Mail-Message-$pkgver.tar.gz")
sha256sums=('e92b0020e0cb11cca92f93df9dd32441d78b84a3c4b72094c0a70310253cac9e')

build() {
  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""                 \
      PERL_AUTOINSTALL=--skipdeps                            \
      PERL_MM_OPT="INSTALLDIRS=vendor DESTDIR='$pkgdir'"     \
      PERL_MB_OPT="--installdirs vendor --destdir '$pkgdir'" \
      MODULEBUILDRC=/dev/null

    cd "$srcdir/Mail-Message-$pkgver"
    /usr/bin/perl Makefile.PL
    make
  )
}

check() {
  cd "$srcdir/Mail-Message-$pkgver"

  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""
    make test
  )
}

package() {
  cd "$srcdir/Mail-Message-$pkgver"
  make install
  find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
}
