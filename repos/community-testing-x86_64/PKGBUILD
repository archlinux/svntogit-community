# Maintainer: Muflone http://www.muflone.com/contacts/english/
# Contributor: John D Jones III AKA jnbek <jnbek1972 -_AT_- g m a i l -_Dot_- com>

pkgname=perl-padwalker
_perl_module=PadWalker
pkgver=2.5
pkgrel=3
pkgdesc="Play with other peoples' lexical variables"
arch=('x86_64')
url="https://metacpan.org/release/${_perl_module}"
license=('PerlArtistic' 'GPL')
depends=('perl')
source=("https://cpan.metacpan.org/authors/id/R/RO/ROBIN/${_perl_module}-${pkgver}.tar.gz")
sha256sums=('07b26abb841146af32072a8d68cb90176ffb176fd9268e6f2f7d106f817a0cd0')
options=('!emptydirs')

build() {
  cd "${_perl_module}-${pkgver}"
  unset PERL5LIB PERL_MM_OPT PERL_MB_OPT PERL_LOCAL_LIB_ROOT
  export PERL_MM_USE_DEFAULT=1 PERL_AUTOINSTALL=--skipdeps
  perl Makefile.PL
  make
}

check() {
  cd "${_perl_module}-${pkgver}"
  unset PERL5LIB PERL_MM_OPT PERL_MB_OPT PERL_LOCAL_LIB_ROOT
  export PERL_MM_USE_DEFAULT=1
  make test
}

package() {
  cd "${_perl_module}-${pkgver}"
  unset PERL5LIB PERL_MM_OPT PERL_MB_OPT PERL_LOCAL_LIB_ROOT
  make pure_install INSTALLDIRS=vendor DESTDIR="${pkgdir}"
}
