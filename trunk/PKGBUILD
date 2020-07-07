# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>

pkgname=perl-test-pod-coverage
pkgver=1.10
pkgrel=4
pkgdesc="CPAN Test::Pod::Coverage module"
arch=('any')
url="https://search.cpan.org/dist/Test-Pod-Coverage/"
license=('PerlArtistic')
depends=('perl-pod-coverage')
options=(!emptydirs)
source=("https://search.cpan.org/CPAN/authors/id/N/NE/NEILB/Test-Pod-Coverage-$pkgver.tar.gz")
md5sums=('c9ea5f4182415b13d2db18484a38c01b')

build() {
  cd  "$srcdir"/Test-Pod-Coverage-$pkgver
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

package() {
  cd  "$srcdir"/Test-Pod-Coverage-$pkgver
  make install DESTDIR="$pkgdir"
  find "$pkgdir" -name '.packlist' -delete
  find "$pkgdir" -name '*.pod' -delete
}
