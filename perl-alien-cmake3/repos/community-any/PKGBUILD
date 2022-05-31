# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-alien-cmake3
pkgver=0.08
pkgrel=3
pkgdesc="Find or download or build cmake 3 or better"
arch=('any')
license=('PerlArtistic')
url="https://metacpan.org/release/Alien-cmake3"
depends=('cmake' 'perl-alien-build')
makedepends=('perl-html-parser' 'perl-sort-versions' 'perl-test2-suite' 'perl-uri')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/P/PL/PLICEASE/Alien-cmake3-$pkgver.tar.gz")
sha512sums=('a5956f488978ff64f9ca8ff7dec06d753731982cd5cf510b45197546e0a091bee37d641a262e7f16901afbb3c42fc3388d76e6a3b92d4be9882e11267eb98494')

build() {
  cd Alien-cmake3-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd Alien-cmake3-$pkgver
  make test
}

package() {
  cd Alien-cmake3-$pkgver
  make DESTDIR="$pkgdir" install
}
