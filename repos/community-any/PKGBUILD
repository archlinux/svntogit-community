# Maintainer: Felix Yan <felixonmars@archlinux.org> 
# Contributor: John D Jones III <jnbek1972 -_AT_- g m a i l -_Dot_- com>

pkgname=perl-super
pkgver=1.20190531
pkgrel=5
pkgdesc="Control superclass method dispatch"
arch=('any')
license=('PerlArtistic' 'GPL')
options=('!emptydirs')
depends=('perl-sub-identify')
url='https://search.cpan.org/dist/SUPER'
source=("https://search.cpan.org/CPAN/authors/id/C/CH/CHROMATIC/SUPER-$pkgver.tar.gz")
sha512sums=('fb1072c76aa9d82edb39ec75f0e14c0fa41837b36b7d2ec24482a20338484cba867646f5e3ceb12ff4f8e1a6f333f5243900c2114d772a29d6c0380feabd3565')

build() {
  cd "$srcdir/SUPER-$pkgver"
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd "$srcdir/SUPER-$pkgver"
  make test
}

package() {
  cd "$srcdir/SUPER-$pkgver"
  make DESTDIR="$pkgdir"/ install
}

# vim:set ts=2 sw=2 et:
