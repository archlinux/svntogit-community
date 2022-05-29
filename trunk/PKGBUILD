# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-probe-perl
pkgver=0.03
pkgrel=5
pkgdesc="Information about the currently running perl"
arch=('any')
license=('PerlArtistic')
url="https://metacpan.org/release/Probe-Perl"
depends=('perl')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/K/KW/KWILLIAMS/Probe-Perl-$pkgver.tar.gz")
sha512sums=('739bdb9d1a74eb77ab885a5aca861a1915cadbb1002bb4cb0d21fc6940ae6b3aa64ee52951ac8b2dca41c9e8fe188e17ae5f3c848c4a1caaf66fec5d25bef49c')

build() {
  cd Probe-Perl-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd Probe-Perl-$pkgver
  make test
}

package() {
  cd Probe-Perl-$pkgver
  make DESTDIR="$pkgdir" install
}
