# Maintainer: Jaroslav Lichtblau <svetlemodry@archlinux.org>
# Contributor: John D Jones III <jnbek1972 -_AT_- g m a i l -_Dot_- com>

pkgname=perl-cpan-changes
pkgver=0.400002
pkgrel=4
pkgdesc="Read and write Changes files"
arch=('any')
url='https://search.mcpan.org/dist/CPAN-Changes'
license=('GPL' 'PerlArtistic')
depends=('perl')
options=('!emptydirs')
source=(https://cpan.metacpan.org/authors/id/H/HA/HAARG/CPAN-Changes-$pkgver.tar.gz)
sha256sums=('01eedea90d07468cb58e4a50bfa3bb1d4eeda9073596add1118fc359153abe8d')

build() {
  cd "${srcdir}"/CPAN-Changes-$pkgver

  PERL_MM_USE_DEFAULT=1 perl Makefile.PL installdirs=vendor
  make
}

check() {
  cd "${srcdir}"/CPAN-Changes-$pkgver

  make test
}

package() {
  cd "${srcdir}"/CPAN-Changes-$pkgver

  make install DESTDIR="${pkgdir}"

  find "${pkgdir}" -name '.packlist' -delete
  find "${pkgdir}" -name '*.pod' -delete
}
