# Maintainer:

pkgname=perl-data-dump
pkgver=1.25
pkgrel=3
pkgdesc="Pretty printing of data structures"
arch=(any)
url="https://metacpan.org/release/Data-Dump"
license=(PerlArtistic GPL)
depends=('perl')
options=(!emptydirs)
source=("https://cpan.metacpan.org/authors/id/G/GA/GARU/Data-Dump-${pkgver}.tar.gz")
sha256sums=('a4aa6e0ddbf39d5ad49bddfe0f89d9da864e3bc00f627125d1bc580472f53fbd')

build() {
  cd Data-Dump-${pkgver}
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd Data-Dump-${pkgver}
  make test
}

package() {
  cd Data-Dump-${pkgver}
  make DESTDIR="$pkgdir" install
}
