# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-lingua-en-inflect
pkgver=1.905
pkgrel=3
pkgdesc='Convert singular to plural. Select "a" or "an"'
arch=('any')
license=('PerlArtistic')
url="https://metacpan.org/release/Lingua-EN-Inflect"
depends=('perl')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/D/DC/DCONWAY/Lingua-EN-Inflect-$pkgver.tar.gz")
sha512sums=('394671c4a645edd426d3f8d7b3980aac10345b68f9c7d2558f46ec3b7ffadad86138c5f27d3afd64e2c193c6d20a537f179ff01aa40a84cd1cee718e4afde42b')

build() {
  cd Lingua-EN-Inflect-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd Lingua-EN-Inflect-$pkgver
  make test
}

package() {
  cd Lingua-EN-Inflect-$pkgver
  make DESTDIR="$pkgdir" install
}
