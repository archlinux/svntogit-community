# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Brian Bidulock <bidulock@openss7.org>

pkgname=perl-canary-stability
_realname=Canary-Stability
pkgver=2013
pkgrel=5
pkgdesc="CPAN/Canary-Stability - canary to check perl compatability for schmorp's modules"
arch=('any')
license=('PerlArtistic' 'GPL')
options=('!emptydirs')
depends=('perl')
url="https://metacpan.org/release/${_realname}"
source=("https://cpan.metacpan.org/authors/id/M/ML/MLEHMANN/${_realname}-${pkgver}.tar.gz")
md5sums=('5368520547521b254317ea0e9b3d23ab')

build() {
  cd "$srcdir/$_realname-$pkgver"
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd "$srcdir/$_realname-$pkgver"
  make test
}

package() {
  cd "$srcdir/$_realname-$pkgver"
  make install DESTDIR="$pkgdir"
}

# vim:set ts=2 sw=2 et:
