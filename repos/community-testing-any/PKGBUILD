# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-test-mockmodule
pkgver=0.177.0
pkgrel=3
pkgdesc="Override subroutines in a module for unit testing"
arch=('any')
license=('PerlArtistic' 'GPL')
options=('!emptydirs')
depends=('perl-super')
makedepends=('perl-module-build')
checkdepends=('perl-test-pod' 'perl-test-pod-coverage' 'perl-test-warnings')
url='https://search.cpan.org/dist/Test-MockModule'
source=("https://search.cpan.org/CPAN/authors/id/G/GF/GFRANKS/Test-MockModule-v$pkgver.tar.gz")
sha512sums=('d28523202ba4dbf040e26a3cb0795297c2c4fc65598e7717a51ed8678bce308eec7eb3b5d5d35d71418b21c2c81833679cf1624e0e07c6b1e26e8f7605eb98b3')

build() {
  cd "$srcdir/Test-MockModule-v$pkgver"
  perl Build.PL installdirs=vendor
  perl Build
}

check() {
  cd "$srcdir/Test-MockModule-v$pkgver"
  perl Build test
}

package() {
  cd "$srcdir/Test-MockModule-v$pkgver"
  perl Build install destdir="$pkgdir"
}

# vim:set ts=2 sw=2 et:
