# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-shell-config-generate
pkgver=0.34
pkgrel=4
pkgdesc="Portably generate config for any shell"
arch=('any')
license=('PerlArtistic')
url="https://metacpan.org/release/Shell-Config-Generate"
depends=('perl-shell-guess')
makedepends=('perl-test2-suite')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/P/PL/PLICEASE/Shell-Config-Generate-$pkgver.tar.gz")
sha512sums=('f78b1613ee26ed6fe7a435f523ac168aaf608f76f1f02470aeb0c540e8bb5c999e4dc86dd4e67230666b5d125ca12a727ab789314c09e1314a5bc5d94534158d')

build() {
  cd Shell-Config-Generate-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd Shell-Config-Generate-$pkgver
  make test
}

package() {
  cd Shell-Config-Generate-$pkgver
  make DESTDIR="$pkgdir" install
}
