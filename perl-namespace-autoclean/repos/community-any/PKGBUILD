# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: John D Jones III AKA jnbek <jnbek1972 -_AT_- g m a i l -_Dot_- com>
# Generator  : CPANPLUS::Dist::Arch 1.32

pkgname=perl-namespace-autoclean
pkgver=0.29
pkgrel=4
pkgdesc="Keep imports out of your namespace"
arch=('any')
license=('PerlArtistic' 'GPL')
url='https://metacpan.org/release/namespace-autoclean'
depends=('perl-b-hooks-endofscope' 'perl-sub-identify' 'perl-namespace-clean')
checkdepends=('perl-test-requires' 'perl-moo' 'perl-sub-name' 'perl-mouse' 'perl-test-needs')
options=('!emptydirs')
source=("https://search.cpan.org/CPAN/authors/id/E/ET/ETHER/namespace-autoclean-$pkgver.tar.gz")
sha512sums=('64dee8009c8ab587c1aef504c0b429248a9069e6cfbfcb4062b83ddf56c82121be66f821013f3251e6863935429e0663aec82202352904983db600a79348732c')

build() {
  cd "$srcdir"/namespace-autoclean-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd "$srcdir"/namespace-autoclean-$pkgver
  make test
}

package() {
  cd "$srcdir"/namespace-autoclean-$pkgver
  make DESTDIR="$pkgdir"/ install
}

# vim:set ts=2 sw=2 et:
