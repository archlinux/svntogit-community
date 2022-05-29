# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-inline-filters
pkgver=0.20
pkgrel=5
pkgdesc="Common source code filters for Inline Modules"
arch=('any')
license=('PerlArtistic')
url="https://metacpan.org/release/Inline-Filters"
depends=('perl-inline' 'perl-inline-c')
checkdepends=('perl-test-pod')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/R/RU/RURBAN/Inline-Filters-$pkgver.tar.gz")
sha512sums=('d1f26682ab7a05bbc1951e87efe94c82b6420633f7f3ce7605e40a4272756a44998ec92c078c1b31dd9e25550c813d19e9829770ad16ae6774cdaf8a85eba620')

build() {
  cd Inline-Filters-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd Inline-Filters-$pkgver
  make test
}

package() {
  cd Inline-Filters-$pkgver
  make DESTDIR="$pkgdir" install
}
