# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-scope-guard
pkgver=0.21
pkgrel=5
pkgdesc="Lexically-scoped resource management"
arch=('any')
license=('PerlArtistic')
url="https://metacpan.org/release/Scope-Guard"
depends=('perl')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/C/CH/CHOCOLATE/Scope-Guard-$pkgver.tar.gz")
sha512sums=('65492e08ab79dc323649166e83ffc13c6f1fffaa9c60d581d8854dfe427a54a3c3c5e4d8b90308d4b1a31a1a54c7977b4e1d36fc9005c6e716c2361ce187fc9f')

build() {
  cd Scope-Guard-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd Scope-Guard-$pkgver
  make test
}

package() {
  cd Scope-Guard-$pkgver
  make DESTDIR="$pkgdir" install
}
