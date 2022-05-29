# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-class-tiny
pkgver=1.008
pkgrel=3
pkgdesc="Minimalist class construction"
arch=('any')
license=('PerlArtistic')
url="https://metacpan.org/release/Class-Tiny"
depends=('perl')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/D/DA/DAGOLDEN/Class-Tiny-$pkgver.tar.gz")
sha512sums=('908eb8547e01036ef361f0a8623d028b1e733ea003fc227788b9c18d0db544a70dbe47de18822f9699a19156f36eac73caeb4849d44eea14ada1128afdb7efbd')

build() {
  cd Class-Tiny-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd Class-Tiny-$pkgver
  make test
}

package() {
  cd Class-Tiny-$pkgver
  make DESTDIR="$pkgdir" install
}
