# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-inline-c
pkgver=0.82
pkgrel=2
pkgdesc="C Language Support for Inline"
arch=('any')
license=('PerlArtistic')
url="https://metacpan.org/release/Inline-C"
depends=('perl-inline' 'perl-parse-recdescent' 'perl-pegex')
makedepends=('perl-file-copy-recursive' 'perl-test-warn')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/E/ET/ETJ/Inline-C-$pkgver.tar.gz")
sha512sums=('1d1e91a63df12b4f3dc631fd1b66f9bd2e006b300002d9aa184ab571a128953722127400a39055d07ee630709f2a7c96dd35ad6e0860959cbb5a6fce3134b357')

build() {
  cd Inline-C-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd Inline-C-$pkgver
  make test
}

package() {
  cd Inline-C-$pkgver
  make DESTDIR="$pkgdir" install
}
