# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Maintainer: Charles Mauch <cmauch@gmail.com>
# Contributor: Francois Charette <firmicus@gmx.net>

pkgname=perl-file-remove
pkgver=1.61
pkgrel=1
pkgdesc="Remove files and directories"
depends=('perl')
arch=('any')
url="https://search.cpan.org/dist/File-Remove"
license=('GPL' 'PerlArtistic')
options=('!emptydirs')
source=(https://search.cpan.org/CPAN/authors/id/S/SH/SHLOMIF/File-Remove-$pkgver.tar.gz)
sha256sums=('fd857f585908fc503461b9e48b3c8594e6535766bc14beb17c90ba58d5dc4975')

build() {
  cd  "$srcdir"/File-Remove-$pkgver
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

package() {
  cd  "$srcdir"/File-Remove-$pkgver
  make install DESTDIR="$pkgdir"
  find "$pkgdir" -name '.packlist' -delete
  find "$pkgdir" -name '*.pod' -delete
}
