# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Firmicus <francois.archlinux.org>

pkgname=perl-test-warn
pkgver=0.37
pkgrel=1
pkgdesc="Perl extension to test methods for warnings "
arch=(any)
url="https://search.cpan.org/dist/Test-Warn/"
license=('GPL' 'PerlArtistic')
depends=('perl-tree-dag-node' 'perl-sub-uplevel>=0.12' 'perl>=5.10.0')
options=('!emptydirs')
source=("https://search.cpan.org/CPAN/authors/id/B/BI/BIGJ/Test-Warn-$pkgver.tar.gz")
sha256sums=('98ca32e7f2f5ea89b8bfb9a0609977f3d153e242e2e51705126cb954f1a06b57')

build() {
  cd  "$srcdir"/Test-Warn-$pkgver
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

package() {
  cd  "$srcdir"/Test-Warn-$pkgver
  make install DESTDIR="$pkgdir"
  find "$pkgdir" -name '.packlist' -delete
  find "$pkgdir" -name '*.pod' -delete
}
