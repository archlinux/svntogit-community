# Maintainer: Jonathan Steel <jsteel at aur.archlinux.org>
# Contributor: Justin Davis <jrcd83@gmail.com>

pkgname=perl-package-stash-xs
pkgver=0.30
pkgrel=1
pkgdesc="Faster and more correct implementation of the Package::Stash API"
arch=('x86_64')
url="https://search.cpan.org/dist/Package-Stash-XS"
license=('PerlArtistic' 'GPL')
depends=('perl')
checkdepends=('perl-test-fatal' 'perl-test-needs')
options=('!emptydirs')
source=(https://search.cpan.org/CPAN/authors/id/E/ET/ETHER/Package-Stash-XS-$pkgver.tar.gz)
sha512sums=('528faaefa71c5c37d378a9bedf325babf3b2717024995d166fc77bb1fb1ce1aed11da775608029a1c215c903dcd7ac9f68569cd8fd3690681ccd72b47c51b0a3')

build() {
  cd Package-Stash-XS-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd Package-Stash-XS-$pkgver
  make test
}

package() {
  cd Package-Stash-XS-$pkgver
  make DESTDIR="$pkgdir" install
}
