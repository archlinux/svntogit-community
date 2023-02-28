# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Francois Charette <firmicus@gmx.net>

pkgname=perl-test-nowarnings
pkgver=1.06
pkgrel=3
pkgdesc="Make sure you didn't emit any warnings while testing "
arch=('any')
url="https://search.cpan.org/dist/Test-NoWarnings"
license=('GPL' 'PerlArtistic')
depends=('perl-test-simple')
options=('!emptydirs')
source=(https://cpan.metacpan.org/authors/id/H/HA/HAARG/Test-NoWarnings-$pkgver.tar.gz)
sha256sums=('c2dc51143b7eb63231210e27df20d2c8393772e0a333547ec8b7a205ed62f737')

build() {
  cd  "$srcdir"/Test-NoWarnings-$pkgver
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

package() {
  cd  "$srcdir"/Test-NoWarnings-$pkgver
  make install DESTDIR="$pkgdir"
  find "$pkgdir" -name '.packlist' -delete
  find "$pkgdir" -name '*.pod' -delete
}
