# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Simon Perry <aur [at] sanxion [dot] net>
# Contributor: Anonymous
# Generator  : CPANPLUS::Dist::Arch 1.29

pkgname=perl-io-captureoutput
pkgver=1.1105
pkgrel=4
pkgdesc="capture STDOUT and STDERR from Perl code, subprocesses or XS"
arch=('any')
license=('PerlArtistic' 'GPL')
options=('!emptydirs')
depends=('perl')
url="https://search.cpan.org/dist/IO-CaptureOutput"
source=("https://search.cpan.org/CPAN/authors/id/D/DA/DAGOLDEN/IO-CaptureOutput-$pkgver.tar.gz")
sha512sums=('8ca9485982d6bfae08ec322c28efd8f673f2a6705421ac5d680c228c436e7a5c8e18a16ff9712062631c35a91e6d19d9518263135db469c47083ce30814cf064')

build() {
  cd IO-CaptureOutput-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd IO-CaptureOutput-$pkgver
  make test
}

package() {
  cd IO-CaptureOutput-$pkgver
  make install DESTDIR="$pkgdir"
}
