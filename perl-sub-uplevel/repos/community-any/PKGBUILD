# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Francois Charette <firmicus@gmx.net>

pkgname=perl-sub-uplevel
pkgver=0.2800
pkgrel=4
pkgdesc="apparently run a function in a higher stack frame "
arch=('any')
url="https://search.cpan.org/dist/Sub-Uplevel"
license=('GPL' 'PerlArtistic')
depends=('perl')
options=('!emptydirs')
source=(https://www.cpan.org/authors/id/D/DA/DAGOLDEN/Sub-Uplevel-$pkgver.tar.gz)
sha256sums=('b4f3f63b80f680a421332d8851ddbe5a8e72fcaa74d5d1d98f3c8cc4a3ece293')

build() {
  cd  "$srcdir"/Sub-Uplevel-$pkgver
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

package() {
  cd  "$srcdir"/Sub-Uplevel-$pkgver
  make install DESTDIR="$pkgdir"
  find "$pkgdir" -name '.packlist' -delete
  find "$pkgdir" -name '*.pod' -delete
}
