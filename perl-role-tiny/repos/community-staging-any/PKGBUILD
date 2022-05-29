# Maintainer: Sergej Pupykin <arch+pub@sergej.pp.ru>
# Contributor: John D Jones III <jnbek1972 -_AT_- g m a i l -_Dot_- com>
# Generator  : CPANPLUS::Dist::Arch 1.29

pkgname='perl-role-tiny'
pkgver=2.002004
pkgrel=3
pkgdesc="Roles. Like a nouvelle cuisine portion size slice of Moose."
arch=('any')
license=('PerlArtistic' 'GPL')
options=('!emptydirs')
depends=('perl')
makedepends=()
checkdepends=('perl-test-fatal>=0.003')
url='https://search.cpan.org/dist/Role-Tiny/'
source=("https://search.cpan.org/CPAN/authors/id/H/HA/HAARG/Role-Tiny-$pkgver.tar.gz")
sha256sums=('d7bdee9e138a4f83aa52d0a981625644bda87ff16642dfa845dcb44d9a242b45')

build() {
  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""                 \
      PERL_AUTOINSTALL=--skipdeps                            \
      PERL_MM_OPT="INSTALLDIRS=vendor DESTDIR='"$pkgdir"'"     \
      PERL_MB_OPT="--installdirs vendor --destdir '"$pkgdir"'" \
      MODULEBUILDRC=/dev/null

    cd "$srcdir/Role-Tiny-$pkgver"
    perl Makefile.PL
    make
  )
}

check() {
  cd "$srcdir/Role-Tiny-$pkgver"
  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""
    make test
  )
}

package() {
  cd "$srcdir/Role-Tiny-$pkgver"
  make install
  find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
}
