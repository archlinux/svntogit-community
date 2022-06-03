# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>

pkgname='perl-types-serialiser'
pkgver=1.01
pkgrel=1
pkgdesc="simple data types for common serialisation formats"
arch=('any')
license=('PerlArtistic' 'GPL')
depends=('perl-common-sense')
makedepends=()
url='https://search.cpan.org/dist/Types-Serialiser'
source=("https://search.cpan.org/CPAN/authors/id/M/ML/MLEHMANN/Types-Serialiser-$pkgver.tar.gz")
md5sums=('4839af5f3fcbacc3945b0e6f3dc9a018')

build() {
  export PERL_MM_USE_DEFAULT=1 PERL5LIB=""                 \
      PERL_AUTOINSTALL=--skipdeps                            \
      PERL_MM_OPT="INSTALLDIRS=vendor DESTDIR='"$pkgdir"'"     \
      PERL_MB_OPT="--installdirs vendor --destdir '"$pkgdir"'" \
      MODULEBUILDRC=/dev/null

  cd "$srcdir/Types-Serialiser-$pkgver"
  perl Makefile.PL
  make
}

check() {
  cd "$srcdir/Types-Serialiser-$pkgver"
  export PERL_MM_USE_DEFAULT=1 PERL5LIB=""
  make test
}

package() {
  cd "$srcdir/Types-Serialiser-$pkgver"
  make install
  find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
}
