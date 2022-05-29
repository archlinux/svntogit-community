# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-string-format
pkgver=1.18
pkgrel=5
pkgdesc="sprintf-like string formatting capabilities with arbitrary format definitions"
arch=('any')
license=('PerlArtistic')
url="https://metacpan.org/release/String-Format"
depends=('perl')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/S/SR/SREZIC/String-Format-$pkgver.tar.gz")
sha512sums=('34eb3991a9bea931f59ca1683ba72d8b07244ed4c2a9409be0626346526b4eb2ab07acdd5c4eabf44a767867a4991e97d89835eb0e4c3c43b413de75eb3c0d5d')

build() {
  cd String-Format-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd String-Format-$pkgver
  make test
}

package() {
  cd String-Format-$pkgver
  make DESTDIR="$pkgdir" install
}
