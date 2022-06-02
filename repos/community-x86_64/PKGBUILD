# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Maintainer: Charles Mauch <cmauch@gmail.com>

pkgname=perl-string-crc32
pkgver=2.100
pkgrel=1
pkgdesc="Perl/CPAN Module String::CRC32 : ZMODEMlike CRC32 generation"
arch=("x86_64")
url="https://search.cpan.org/dist/String-CRC32"
license=("GPL" "PerlArtistic")
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/L/LE/LEEJO/String-CRC32-$pkgver.tar.gz")
sha256sums=('9706093b2d068b6715d35b4c58f51558e37960083202129fbb00a57e19a74713')

build() {
  cd String-CRC32-${pkgver}

  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor

  make
}

package() {
  cd String-CRC32-${pkgver}

  make pure_install doc_install DESTDIR="$pkgdir"

  find "$pkgdir" -name '.packlist' -delete
  find "$pkgdir" -name '*.pod' -delete
}
