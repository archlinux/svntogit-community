# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-pkgconfig-libpkgconf
pkgver=0.11
pkgrel=4
pkgdesc="Perl bindings for libpkgconf"
arch=('x86_64')
license=('PerlArtistic')
url="https://metacpan.org/release/PkgConfig-LibPkgConf"
depends=('perl' 'pkgconf')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/P/PL/PLICEASE/PkgConfig-LibPkgConf-$pkgver.tar.gz")
sha512sums=('d9205b364c03dd9ab15128f65e4fbf79c81e3dbd8112d2d94c886e521aa8691907d490698c75c43cb2167ee0d96cf76c36c9930f032f65c5785257b658ca55d4')

build() {
  cd PkgConfig-LibPkgConf-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd PkgConfig-LibPkgConf-$pkgver
  make test
}

package() {
  cd PkgConfig-LibPkgConf-$pkgver
  make DESTDIR="$pkgdir" install
}
