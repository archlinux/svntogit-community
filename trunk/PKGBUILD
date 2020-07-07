# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>

pkgname=perl-class-load
pkgver=0.25
pkgrel=2
pkgdesc="a working (require 'Class::Name') and more"
arch=('any')
license=('PerlArtistic' 'GPL')
url="https://search.cpan.org/dist/Class-Load"
options=(!emptydirs)
depends=('perl' 'perl-module-runtime' 'perl-data-optlist' 'perl-package-stash>=0.32'
	 'perl-try-tiny' 'perl-test-fatal' 'perl-module-implementation'
	 'perl-namespace-clean')
source=(https://search.cpan.org/CPAN/authors/id/E/ET/ETHER/Class-Load-$pkgver.tar.gz)
sha256sums=('2a48fa779b5297e56156380e8b32637c6c58decb4f4a7f3c7350523e11275f8f')

build() {
  cd "${srcdir}/Class-Load-${pkgver}"
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
#  make test
}

package() {
  cd "${srcdir}/Class-Load-${pkgver}"
  make install DESTDIR="$pkgdir"
  find "$pkgdir" -name perllocal.pod -delete
  find "$pkgdir" -name .packlist -delete
}
