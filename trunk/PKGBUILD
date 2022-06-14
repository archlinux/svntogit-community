# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>

pkgname=perl-specio
pkgver=0.48
pkgrel=1
pkgdesc="Type constraints and coercions for Perl"
arch=('any')
url="https://search.cpan.org/dist/Specio"
license=('GPL' 'PerlArtistic')
depends=('perl-role-tiny' 'perl-test-fatal' 'perl-mro-compat' 'perl-devel-stacktrace')
options=('!emptydirs')
source=(https://search.cpan.org/CPAN/authors/id/D/DR/DROLSKY/Specio-$pkgver.tar.gz)
sha256sums=('0c85793580f1274ef08173079131d101f77b22accea7afa8255202f0811682b2')

build() {
  cd  "$srcdir"/Specio-$pkgver
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor 
  make
}
package() {
  cd  "$srcdir"/Specio-$pkgver
  make install DESTDIR="$pkgdir"
  find "$pkgdir" -name '.packlist' -delete
  find "$pkgdir" -name '*.pod' -delete
}
