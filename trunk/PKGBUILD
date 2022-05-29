# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>

pkgname=perl-file-slurp-tiny
pkgver=0.004
pkgrel=8
pkgdesc="A simple, sane and efficient file slurper"
arch=('any')
license=('PerlArtistic' 'GPL')
options=('!emptydirs')
depends=('perl')
makedepends=()
url='https://search.cpan.org/dist/File-Slurp-Tiny'
source=("https://search.cpan.org/CPAN/authors/id/L/LE/LEONT/File-Slurp-Tiny-$pkgver.tar.gz")
md5sums=('7575b81543281ea57cdb7e5eb3f73264')

build() {
  cd "$srcdir/File-Slurp-Tiny-$pkgver"
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd "$srcdir/File-Slurp-Tiny-$pkgver"
  PERL_MM_USE_DEFAULT=1
  make test
}

package() {
  cd "$srcdir/File-Slurp-Tiny-$pkgver"
  make install DESTDIR="$pkgdir"
  find "$pkgdir" -name '.packlist' -o -name '*.pod' -delete
}
