# Maintainer: Jaroslav Lichtblau <svetlemodry@archlinux.org>
# Contributor: Maxwell Pray a.k.a. Synthead <synthead@gmail.com>
# Contributor: Caleb Cushing <xenoterracide@gmail.com>

pkgname=perl-exception-class
pkgver=1.45
pkgrel=2
pkgdesc='A module that allows you to declare real exception classes in Perl'
arch=('any')
url="https://metacpan.org/release/Exception-Class"
license=('PerlArtistic' 'GPL')
depends=('perl>=5.8.1' 'perl-class-data-inheritable>=0.02' 'perl-devel-stacktrace>=2.00')
options=('!emptydirs')
source=(https://search.cpan.org/CPAN/authors/id/D/DR/DROLSKY/Exception-Class-$pkgver.tar.gz)
sha256sums=('5482a77ef027ca1f9f39e1f48c558356e954936fc8fbbdee6c811c512701b249')

build() {
  cd "${srcdir}"/Exception-Class-$pkgver

  export PERL_MM_USE_DEFAULT=1 PERL_AUTOINSTALL=--skipdeps
  unset PERL5LIB PERL_MM_OPT
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd "${srcdir}"/Exception-Class-$pkgver

  export PERL_MM_USE_DEFAULT=1
  unset PERL5LIB
  make test
}

package() {
  cd "${srcdir}"/Exception-Class-$pkgver

  make install INSTALLDIRS=vendor DESTDIR="${pkgdir}"

  find "${pkgdir}" -name .packlist -o -name perllocal.pod -delete
}
