# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-file-homedir
pkgver=1.006
pkgrel=3
pkgdesc="Find your home and other directories on any platform"
arch=('any')
license=('PerlArtistic')
url="https://metacpan.org/release/File-HomeDir"
depends=('perl-file-which')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/R/RE/REHSACK/File-HomeDir-$pkgver.tar.gz")
sha512sums=('1ea90d68ed059ef5e890f6afb1280673dd5a597956f282c4ae8b4471c1751aa3cb2fcbe9caa6b2976937d11fd7233aa85a2dea611f87c79e0ddd1a501ceb890d')

build() {
  cd File-HomeDir-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd File-HomeDir-$pkgver
  make test
}

package() {
  cd File-HomeDir-$pkgver
  make DESTDIR="$pkgdir" install
}
