# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-inline-cpp
pkgver=0.80
pkgrel=5
pkgdesc="Write Perl subroutines and classes in C++"
arch=('any')
license=('PerlArtistic')
url="https://metacpan.org/release/Inline-CPP"
depends=('perl-inline' 'perl-inline-c' 'perl-parse-recdescent')
makedepends=('perl-extutils-cppguess')
checkdepends=('perl-inline-filters')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/D/DA/DAVIDO/Inline-CPP-$pkgver.tar.gz")
sha512sums=('7c86d712131306483e04b87eafcee86fea178dc791d85341cfb1c727718a3679d93f935abce5de5ef32adb627d802bbb391bc8842bcf0a1c38c688dc9182a73f')

build() {
  cd Inline-CPP-$pkgver
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd Inline-CPP-$pkgver
  make test
}

package() {
  cd Inline-CPP-$pkgver
  make DESTDIR="$pkgdir" install
}
