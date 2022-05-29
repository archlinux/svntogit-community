# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-importer
pkgver=0.026
pkgrel=3
pkgdesc="Alternative but compatible interface to modules that export symbols."
arch=('any')
license=('PerlArtistic')
url="https://metacpan.org/release/Importer"
depends=('perl')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/E/EX/EXODIST/Importer-$pkgver.tar.gz")
sha512sums=('f6726b204ee358af00b5c72120bd2131ed575c100a9946b1772552e42b98f78dd38ffcc0119e2cdf721c39e2d83547bc5778adb61c5f84089caf11949c7ef045')

build() {
  cd Importer-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd Importer-$pkgver
  make test
}

package() {
  cd Importer-$pkgver
  make DESTDIR="$pkgdir" install
}
