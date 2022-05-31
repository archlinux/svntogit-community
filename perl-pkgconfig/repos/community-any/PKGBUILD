# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-pkgconfig
pkgver=0.25026
pkgrel=3
pkgdesc="Pure-Perl Core-Only replacement for pkg-config"
arch=('any')
license=('PerlArtistic')
url="https://metacpan.org/release/PkgConfig"
depends=('perl')
checkdepends=('perl-capture-tiny' 'perl-test-minimumversion')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/P/PL/PLICEASE/PkgConfig-$pkgver.tar.gz")
sha512sums=('63992267a8dfbac69a36fbc64b40558d0b63cd93f08d46a067812ffb49f2c7faef67d03fc2fe32e0fba22877bf41663ff2debe38d9eacdf87bd187f227698ab7')

build() {
  cd PkgConfig-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd PkgConfig-$pkgver
  make test
}

package() {
  cd PkgConfig-$pkgver
  make DESTDIR="$pkgdir" install
}
