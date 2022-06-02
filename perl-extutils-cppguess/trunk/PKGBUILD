# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-extutils-cppguess
pkgver=0.26
pkgrel=1
pkgdesc="Guess C++ compiler and flags"
arch=('any')
license=('PerlArtistic')
url="https://metacpan.org/release/ExtUtils-CppGuess"
depends=('perl-capture-tiny')
makedepends=('perl-module-build')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/E/ET/ETJ/ExtUtils-CppGuess-$pkgver.tar.gz")
sha512sums=('35e8e11f7df5d4a2a306cbe1df7a879291cb041677c740d95fc228e8ee812a127be4c70bc2ae6b25d3e73de69e1796539dacf3bb0b1a3311de3dea588335a225')

build() {
  cd ExtUtils-CppGuess-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd ExtUtils-CppGuess-$pkgver
  make test
}

package() {
  cd ExtUtils-CppGuess-$pkgver
  make DESTDIR="$pkgdir" install
}
