# Maintainer: Sébastien Luttringer

pkgname=perl-test-output
pkgver=1.033
pkgrel=3
pkgdesc='Utilities to test STDOUT and STDERR messages'
arch=('any')
license=('GPL' 'PerlArtistic')
depends=('perl-sub-exporter'
  'perl-test-simple'
  'perl-test-pod'
  'perl-test-pod-coverage'
  'perl-capture-tiny')
url='https://search.cpan.org/dist/Test-Output'
options=('!emptydirs')
source=("https://search.cpan.org/CPAN/authors/id/B/BD/BDFOY/Test-Output-$pkgver.tar.gz")
sha512sums=('cc6e94baa5163e2ca0c23d63a6b505da207ed7f436bf9a1a77234ad898c34ae4d81ac42f17d1b8a73a223fd19ce1d1f66f3eef0fc852bb712f4f925a77f29820')

build() {
  cd Test-Output-$pkgver
  USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd Test-Output-$pkgver
  make test
}

package() {
  cd Test-Output-$pkgver
  make install DESTDIR="$pkgdir/"
}

# vim:set ts=2 sw=2 et:
