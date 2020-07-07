# Maintainer: Jaroslav Lichtblau <svetlemodry@archlinux.org>
# Contributor: John D Jones III <jnbek1972 -_AT_- g m a i l -_Dot_- com>

pkgname=perl-readonly
pkgver=2.05
pkgrel=4
pkgdesc="Facility for creating read-only scalars, arrays, hashes"
arch=('any')
url='https://search.mcpan.org/dist/Readonly'
license=('GPL' 'PerlArtistic')
depends=('perl')
makedepends=('perl-module-build-tiny')
options=('!emptydirs')
source=(https://search.mcpan.org/CPAN/authors/id/S/SA/SANKO/Readonly-$pkgver.tar.gz)
sha256sums=('4b23542491af010d44a5c7c861244738acc74ababae6b8838d354dfb19462b5e')

build() {
  cd "${srcdir}"/Readonly-$pkgver

  perl Build.PL --installdirs=vendor
  ./Build
}

check() {
  cd "${srcdir}"/Readonly-$pkgver

  ./Build test
}

package() {
  cd "${srcdir}"/Readonly-$pkgver

  ./Build install --destdir="${pkgdir}"

  find "${pkgdir}" -name '.packlist' -delete
  find "${pkgdir}" -name '*.pod' -delete
}
