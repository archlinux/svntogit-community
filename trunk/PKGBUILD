# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: François Charette <firmicus ατ gmx δοτ net>

pkgname=perl-inline
pkgver=0.86
pkgrel=1
pkgdesc="Write Perl subroutines in other languages"
arch=('any')
url="https://search.cpan.org/dist/Inline"
license=('GPL' 'PerlArtistic')
depends=('perl>=5.10.0' 'perl-parse-recdescent>=1.8')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/I/IN/INGY/Inline-$pkgver.tar.gz")
sha256sums=('510a7de2d011b0db80b0874e8c0f7390010991000ae135cff7474df1e6d51e3a')

build() {
  cd  "$srcdir"/Inline-$pkgver
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

package() {
  cd  "$srcdir"/Inline-$pkgver
  make install DESTDIR="$pkgdir"
  find "$pkgdir" -name '.packlist' -delete
  find "$pkgdir" -name '*.pod' -delete
}
