# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Francois Charette <firmicus@gmx.net>

pkgname=perl-time-duration
epoch=1
pkgver=1.21
pkgrel=1
pkgdesc="rounded or exact English expression of durations"
arch=('any')
url="https://search.cpan.org/dist/Time-Duration"
license=('GPL' 'PerlArtistic')
depends=('perl')
makedepends=('perl-test-pod-coverage' 'perl-test-pod')
options=('!emptydirs')
source=(https://search.cpan.org/CPAN/authors/id/N/NE/NEILB/Time-Duration-$pkgver.tar.gz)
md5sums=('451be4126045398c48bb7e36ae525453')

build() {
  cd  "$srcdir"/Time-Duration-${pkgver}
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

package() {
  cd  "$srcdir"/Time-Duration-${pkgver}
  make install DESTDIR="$pkgdir"
  find "$pkgdir" -name '.packlist' -delete
  find "$pkgdir" -name '*.pod' -delete
}
