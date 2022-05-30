# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Tor Krill <tor@krill.nu>

pkgname=perl-json-xs
pkgver=4.03
pkgrel=3
pkgdesc="JSON::XS - JSON serialising/deserialising, done correctly and fast"
url="https://search.cpan.org/dist/JSON-XS/"
license=("GPL")
arch=('x86_64')
depends=('perl' 'perl-common-sense' 'perl-types-serialiser')
makedepends=('perl-canary-stability')
options=('!emptydirs')
source=(https://search.cpan.org/CPAN/authors/id/M/ML/MLEHMANN/JSON-XS-$pkgver.tar.gz)
sha256sums=('515536f45f2fa1a7e88c8824533758d0121d267ab9cb453a1b5887c8a56b9068')

build() {
  cd  "$srcdir"/JSON-XS-$pkgver
  PERL_CANARY_STABILITY_NOPROMPT=1 \
  perl Makefile.PL INSTALLDIRS=vendor
  make
}
package() {
  cd  "$srcdir"/JSON-XS-$pkgver
  make DESTDIR="$pkgdir" install

  find "$pkgdir" -name '.packlist' -delete && \
  find "$pkgdir" -name '*.pod' -delete
}
