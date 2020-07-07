# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: François Charette <firmicus ατ gmx δοτ net>

pkgname=perl-spiffy
pkgver=0.46
pkgrel=4
pkgdesc="Spiffy Perl Interface Framework For You"
arch=('any')
url="https://search.cpan.org/dist/Spiffy"
license=('GPL' 'PerlArtistic')
depends=('perl>=5.10.0')
options=('!emptydirs')
source=(https://www.cpan.org/authors/id/I/IN/INGY/Spiffy-$pkgver.tar.gz)
sha256sums=('8f58620a8420255c49b6c43c5ff5802bd25e4f09240c51e5bf2b022833d41da3')

build() {
  cd  "$srcdir"/Spiffy-$pkgver
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

package() {
  cd  "$srcdir"/Spiffy-$pkgver
  make install DESTDIR="$pkgdir"
  find "$pkgdir" -name '.packlist' -delete
  find "$pkgdir" -name '*.pod' -delete
}
