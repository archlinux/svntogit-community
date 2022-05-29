# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-shell-guess
pkgver=0.09
pkgrel=5
pkgdesc="Make an educated guess about the shell in use"
arch=('any')
license=('PerlArtistic')
url="https://metacpan.org/release/Shell-Guess"
depends=('perl')
checkdepends=('tcsh')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/P/PL/PLICEASE/Shell-Guess-$pkgver.tar.gz")
sha512sums=('60d8b315491cd10eb2cb1c3941db6369d93148e0bd500c72bc082b1673624dead6485d4238e241127c3a04a0f776222fbb90a40af6a327ed9e2988852fff544e')

build() {
  cd Shell-Guess-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd Shell-Guess-$pkgver
  make test
}

package() {
  cd Shell-Guess-$pkgver
  make DESTDIR="$pkgdir" install
}
