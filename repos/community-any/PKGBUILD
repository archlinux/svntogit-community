# Maintainer: Jonathan Steel <jsteel@aur.archlinux.org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Justin Davis <jrcd83@gmail.com>

pkgname=perl-test-requires
pkgver=0.11
pkgrel=4
pkgdesc="Checks to see if the module can be loaded"
arch=('any')
license=('PerlArtistic' 'GPL')
options=('!emptydirs')
depends=('perl')
url='https://search.cpan.org/dist/Test-Requires'
source=("https://search.cpan.org/CPAN/authors/id/T/TO/TOKUHIROM/Test-Requires-$pkgver.tar.gz")
sha512sums=('770ea2469e386296fe1ded3630fa9b7f30ee22acd3522fb83ad95171ccb96812ef2fc5fa30d658a405dc1c435d35b6d476cc054021d74e04b419b517f6f898fa')

build() {
  cd "$srcdir"/Test-Requires-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd "$srcdir"/Test-Requires-$pkgver
  make test
}

package() {
  cd "$srcdir"/Test-Requires-$pkgver
  make DESTDIR="$pkgdir"/ install
}
