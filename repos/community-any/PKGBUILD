# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: François Charette <firmicus ατ gmx δοτ net>

pkgname=perl-datetime-format-w3cdtf
pkgver=0.08
pkgrel=3
pkgdesc="Parse and format W3CDTF datetime strings"
arch=('any')
url="https://search.cpan.org/dist/DateTime-Format-W3CDTF"
license=('GPL' 'PerlArtistic')
depends=('perl>=5.10.0' 'perl-datetime')
options=('!emptydirs')
source=(https://search.cpan.org/CPAN/authors/id/G/GW/GWILLIAMS/DateTime-Format-W3CDTF-$pkgver.tar.gz)
sha256sums=('dcc200a073a21cba48122a5dae0b6a875df93d3f8c8ae9d446dcdd9befaa413a')

build() {
  cd  "$srcdir"/DateTime-Format-W3CDTF-$pkgver
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

package() {
  cd  "$srcdir"/DateTime-Format-W3CDTF-$pkgver
  make install DESTDIR="$pkgdir"
  find "$pkgdir" -name '.packlist' -delete
  find "$pkgdir" -name '*.pod' -delete
}
