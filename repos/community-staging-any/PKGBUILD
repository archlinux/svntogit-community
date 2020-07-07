# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Maintainer: Charles Mauch <cmauch@gmail.com>
# Contributor: Francois Charette <firmicus@gmx.net>

pkgname=perl-file-chdir
pkgver=0.1011
pkgrel=4
pkgdesc="a more sensible way to change directories "
arch=('any')
depends=('perl')
url="https://search.cpan.org/dist/File-chdir"
license=('GPL' 'PerlArtistic')
options=('!emptydirs')
source=(https://www.cpan.org/authors/id/D/DA/DAGOLDEN/File-chdir-$pkgver.tar.gz)
sha256sums=('31ebf912df48d5d681def74b9880d78b1f3aca4351a0ed1fe3570b8e03af6c79')

build() {
  cd  "$srcdir"/File-chdir-$pkgver
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

package() {
  cd  "$srcdir"/File-chdir-$pkgver
  make install DESTDIR="$pkgdir"
  find "$pkgdir" -name '.packlist' -delete
  find "$pkgdir" -name '*.pod' -delete
}
