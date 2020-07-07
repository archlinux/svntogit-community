# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Francois Charette <firmicus@gmx.net>

pkgname=perl-pod-coverage
pkgver=0.23
pkgrel=5
pkgdesc="Checks if the documentation of a module is comprehensive "
arch=('any')
url="https://search.cpan.org/dist/Pod-Coverage"
license=('GPL' 'PerlArtistic')
depends=('perl-devel-symdump' 'perl-pod-parser')
options=('!emptydirs')
source=(https://www.cpan.org/authors/id/R/RC/RCLAMP/Pod-Coverage-$pkgver.tar.gz)
sha256sums=('30b7a0b0c942f44a7552c0d34e9b1f2e0ba0b67955c61e3b1589ec369074b107')

build() {
  cd  "$srcdir"/Pod-Coverage-$pkgver
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd  "$srcdir"/Pod-Coverage-$pkgver
  make test
}

package() {
  cd  "$srcdir"/Pod-Coverage-$pkgver
  make install DESTDIR="$pkgdir"
  find "$pkgdir" -name '.packlist' -delete
  find "$pkgdir" -name '*.pod' -delete
}
