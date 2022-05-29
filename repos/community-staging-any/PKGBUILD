# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-test-script
pkgver=1.29
pkgrel=3
pkgdesc="Basic cross-platform tests for scripts"
arch=('any')
license=('PerlArtistic')
url="https://metacpan.org/release/Test-Script"
depends=('perl-capture-tiny' 'perl-probe-perl' 'perl-test2-suite')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/P/PL/PLICEASE/Test-Script-$pkgver.tar.gz")
sha512sums=('979fade0abc83f8d7d4c1c094fa928e27bd7c9db52140b156689d3b192d9ea84f5824554d6788c9144cf2923a04b1d8a8bdfdcc05a0be5514de92353c9a7d10f')

build() {
  cd Test-Script-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd Test-Script-$pkgver
  make test
}

package() {
  cd Test-Script-$pkgver
  make DESTDIR="$pkgdir" install
}
