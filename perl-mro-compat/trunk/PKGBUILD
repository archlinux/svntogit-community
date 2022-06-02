# Maintainer: Sergej Pupykin <arch+pub@sergej.pp.ru>
pkgname='perl-mro-compat'
pkgver=0.15
pkgrel=1
pkgdesc="mro::* interface compatibility for Perls < 5.9.5"
arch=('any')
license=('PerlArtistic' 'GPL')
options=('!emptydirs')
depends=('perl')
makedepends=()
url='https://search.cpan.org/dist/MRO-Compat'
source=("https://search.cpan.org/CPAN/authors/id/H/HA/HAARG/MRO-Compat-$pkgver.tar.gz")
sha256sums=('0d4535f88e43babd84ab604866215fc4d04398bd4db7b21852d4a31b1c15ef61')

build() {
  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""                 \
      PERL_AUTOINSTALL=--skipdeps                            \
      PERL_MM_OPT="INSTALLDIRS=vendor DESTDIR='"$pkgdir"'"     \
      PERL_MB_OPT="--installdirs vendor --destdir '"$pkgdir"'" \
      PERL_USE_UNSAFE_INC=1 \
      MODULEBUILDRC=/dev/null

    cd "${srcdir}/MRO-Compat-${pkgver}"
    /usr/bin/perl Makefile.PL
    make
  )
}

check() {
  cd "${srcdir}/MRO-Compat-${pkgver}"
  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""
    make test
  )
}

package() {
  cd "${srcdir}/MRO-Compat-${pkgver}"
  make install
  find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
}

# Local Variables:
# mode: shell-script
# sh-basic-offset: 2
# End:
# vim:set ts=2 sw=2 et:
