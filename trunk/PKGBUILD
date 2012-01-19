# Maintainet: Alessandro Sagratini <ale_sagra at hotmail dot com>
# Contributor:  Philippe LUC <philfifi@gmail.com>
_author=muir
_perlmod=Time-modules
pkgname=perl-time-modules
pkgver=2011.0517
pkgrel=1
pkgdesc="Parses Date strings"
url="http://search.cpan.org/~muir/Time-modules-$pkgver/"
license=('GPL' 'PerlArtistic')
depends=('perl>=5.10.0')
options=('!emptydirs')
arch=(any)
source=(http://search.cpan.org/CPAN/authors/id/M/MU/MUIR/modules/$_perlmod-$pkgver.tar.gz) 
md5sums=('67204ebc06211a877665765f91dc4e51')

build() {
  cd "$srcdir/$_perlmod-$pkgver"

  # Install module in vendor directories.
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make

  ## For packages with Build.PL, do this instead:
  # perl Build.PL installdirs=vendor destdir="$pkgdir/"
  # perl Build
}

package() {
  cd "$srcdir/$_perlmod-$pkgver"
  make install DESTDIR="$pkgdir/"

  ## For packages with Build.PL, do this instead:
  # perl Build install
}
