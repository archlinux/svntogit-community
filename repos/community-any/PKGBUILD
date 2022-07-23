# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-ppi
pkgver=1.276
pkgrel=1
pkgdesc="Parse, Analyze and Manipulate Perl (without perl)"
arch=('any')
license=('PerlArtistic')
url="https://metacpan.org/release/PPI"
depends=('perl-clone' 'perl-io-string' 'perl-list-moreutils' 'perl-params-util' 'perl-task-weaken')
makedepends=('perl-class-inspector' 'perl-file-remove' 'perl-test-deep' 'perl-test-object'
             'perl-test-subcalls')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/O/OA/OALDERS/PPI-$pkgver.tar.gz")
sha512sums=('fb6ed20e7d36ac83757107a7d075bc7a387cb32a83e5927b47423b7705f7b7d2b05762bd21d480d75cda494fee9a40d789515c84efec5c2f2e4a1041524e3af0')

build() {
  cd PPI-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd PPI-$pkgver
  make test
}

package() {
  cd PPI-$pkgver
  make DESTDIR="$pkgdir" install
}
