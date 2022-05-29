# Maintainer: Jaroslav Lichtblau <svetlemodry@archlinux.org>
# Contributor: Moritz Bunkus <moritz@bunkus.org>

pkgname=perl-devel-stacktrace
pkgver=2.04
pkgrel=2
pkgdesc='An object representing a stack trace'
arch=('any')
url="https://metacpan.org/release/Devel-StackTrace"
license=('PerlArtistic' 'GPL')
depends=('perl>=5.6')
options=('!emptydirs')
source=(https://search.cpan.org/CPAN/authors/id/D/DR/DROLSKY/Devel-StackTrace-$pkgver.tar.gz)
sha256sums=('cd3c03ed547d3d42c61fa5814c98296139392e7971c092e09a431f2c9f5d6855')

build() {
  cd "${srcdir}"/Devel-StackTrace-$pkgver

  export PERL_MM_USE_DEFAULT=1 PERL_AUTOINSTALL=--skipdeps
  unset PERL5LIB PERL_MM_OPT
  perl Makefile.PL
  make
}

check() {
  cd "${srcdir}"/Devel-StackTrace-$pkgver

  export PERL_MM_USE_DEFAULT=1
  unset PERL5LIB
  make test
}

package() {
  cd "${srcdir}"/Devel-StackTrace-$pkgver

  make install INSTALLDIRS=vendor DESTDIR="${pkgdir}"

  find "${pkgdir}" -name .packlist -o -name perllocal.pod -delete
}
