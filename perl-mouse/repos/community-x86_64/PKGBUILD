# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-mouse
pkgver=2.5.10
pkgrel=4
pkgdesc="Moose minus the antlers"
arch=('x86_64')
url="https://search.cpan.org/dist/Mouse"
license=('PerlArtistic' 'GPL')
depends=('perl')
makedepends=('perl-test-exception' 'perl-test-fatal' 'perl-module-build'
             'perl-module-build-xsutil' 'perl-test-requires'
             'perl-test-leaktrace' 'perl-test-output' 'perl-test-deep'
             'perl-io-string')
checkdepends=('perl-path-class')
source=(https://search.cpan.org/CPAN/authors/id/S/SK/SKAJI/Mouse-v$pkgver.tar.gz)
sha512sums=('949a2f18257a5afcf4dbbb84094974f4d80e1e4531b4b9d8618cf141252fd11b09b79daafe1de79faa620905988f649627bc2fceac357ea2f180db74cd48f711')

build() {
  cd Mouse-v$pkgver
  perl Build.PL --installdirs=vendor
  ./Build
}

check() {
  cd Mouse-v$pkgver
  ./Build test
}

package() {
  cd Mouse-v$pkgver
  ./Build install --destdir="${pkgdir}"
}
