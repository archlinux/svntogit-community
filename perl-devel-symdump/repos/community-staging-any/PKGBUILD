# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: François Charette <firmicus ατ gmx δοτ net>

pkgname=perl-devel-symdump
pkgver=2.18
pkgrel=4
pkgdesc="Perl symbol table access and dumping"
arch=('any')
url="https://search.cpan.org/dist/Devel-Symdump"
license=('GPL' 'PerlArtistic')
depends=('perl>=5.10.0')
options=('!emptydirs')
source=(https://www.cpan.org/authors/id/A/AN/ANDK/Devel-Symdump-$pkgver.tar.gz)
sha256sums=('826f81a107f5592a2516766ed43beb47e10cc83edc9ea48090b02a36040776c0')

build() {
  cd  "$srcdir"/Devel-Symdump-$pkgver
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

package() {
  cd  "$srcdir"/Devel-Symdump-$pkgver
  make install DESTDIR="$pkgdir"
  find "$pkgdir" -name '.packlist' -delete
  find "$pkgdir" -name '*.pod' -delete
}
