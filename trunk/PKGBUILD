# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Christos Nouskas <nous@archlinux.us>
# Generator  : CPANPLUS::Dist::Arch 1.28

pkgname=perl-test-utf8
pkgver=1.02
pkgrel=1
pkgdesc="handy utf8 tests"
arch=('any')
url='https://search.cpan.org/dist/Test-utf8'
license=('PerlArtistic' 'GPL')
options=('!emptydirs')
depends=('perl')
makedepends=('perl-module-install')
source=("https://search.cpan.org/CPAN/authors/id/M/MA/MARKF/Test-utf8-$pkgver.tar.gz")
sha512sums=('f544174ad570c5e027acf66dcf335ddc4be3727488559933a389dbd7f2214e66490f96d0e816677310468076719d891fa3da80524b2b10345d8be8eebf4a1469')

build() {
  cd Test-utf8-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd Test-utf8-$pkgver
  make test
}

package() {
  cd Test-utf8-$pkgver
  make DESTDIR="$pkgdir" install
}
