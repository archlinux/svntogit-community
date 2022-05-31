# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=perl-file-find-rule-perl
pkgver=1.16
pkgrel=2
pkgdesc="Common rules for searching for Perl things"
arch=('any')
license=('PerlArtistic')
url="https://metacpan.org/release/File-Find-Rule-Perl"
depends=('perl-file-find-rule' 'perl-params-util')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/E/ET/ETHER/File-Find-Rule-Perl-$pkgver.tar.gz")
sha512sums=('750e59c2aed55e7a73f9dbc67654d7f9de39b744967caa31510f9234bb71437cdd821babf7b80f435d6a968e9d4a49df503449683e866e090c7f120c56e20a47')

build() {
  cd File-Find-Rule-Perl-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd File-Find-Rule-Perl-$pkgver
  make test
}

package() {
  cd File-Find-Rule-Perl-$pkgver
  make DESTDIR="$pkgdir" install
}
