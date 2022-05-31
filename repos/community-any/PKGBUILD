# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Jonathan Steel <jsteel@aur.archlinux.org>
# Contributor: Justin Davis <jrcd83@gmail.com>

pkgname=perl-package-stash
pkgver=0.40
pkgrel=2
pkgdesc="Routines for manipulating stashes"
arch=('any')
url="https://search.cpan.org/dist/Package-Stash"
license=('PerlArtistic' 'GPL')
depends=('perl-dist-checkconflicts' 'perl-package-stash-xs' 'perl-module-implementation')
checkdepends=('perl-cpan-meta-check' 'perl-test-fatal' 'perl-test-needs')
options=('!emptydirs')
source=(https://search.cpan.org/CPAN/authors/id/E/ET/ETHER/Package-Stash-$pkgver.tar.gz)
sha512sums=('1a1e358c8409ba0bcc2fee9b3cc86b6cd42297c9bd0641a57872bec498567ee18075ad71f7e79bb9b3a789cb47ebbf852163886f8babaf3aa23e7ff9eb2e7080')

build() {
  cd Package-Stash-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd Package-Stash-$pkgver
  make test
}

package() {
  cd Package-Stash-$pkgver
  make DESTDIR="$pkgdir" install
}
