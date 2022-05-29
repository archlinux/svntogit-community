# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-ppix-utilities
pkgver=1.001000
pkgrel=5
pkgdesc="Extensions to L<PPI|PPI>"
arch=('any')
license=('PerlArtistic')
url="https://metacpan.org/release/PPIx-Utilities"
depends=('perl-exception-class' 'perl-ppi' 'perl-readonly' 'perl-task-weaken')
makedepends=('perl-test-deep')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/E/EL/ELLIOTJS/PPIx-Utilities-$pkgver.tar.gz")
sha512sums=('46b900b4152e83e7a37b3fb6036051079aed677f0a33affa07f50e33a3a45bc220c899ecb99a1ab259a934aa9801582e804fe3be2980188c6442774de9b0f6de')

build() {
  cd PPIx-Utilities-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd PPIx-Utilities-$pkgver
  make test
}

package() {
  cd PPIx-Utilities-$pkgver
  make DESTDIR="$pkgdir" install
}
