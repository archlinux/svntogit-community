# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Maintainer: Charles Mauch <cmauch@gmail.com>
# Contributor: Francois Charette <firmicus@gmx.net>

pkgname=perl-cache-memcached
pkgver=1.30
pkgrel=4
pkgdesc="client library for memcached (memory cache daemon) "
arch=(any)
url="https://search.cpan.org/dist/Cache-Memcached"
license=('GPL' 'PerlArtistic')
depends=('perl-string-crc32')
options=('!emptydirs')
source=(https://search.cpan.org/CPAN/authors/id/D/DO/DORMANDO/Cache-Memcached-$pkgver.tar.gz)
md5sums=('6f87a85c8dee38fb9ebf1df56cb07f7b')

build() {
  cd  "$srcdir"/Cache-Memcached-$pkgver
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

package() {
  cd  "$srcdir"/Cache-Memcached-$pkgver
  make pure_install doc_install DESTDIR="$pkgdir"
  find "$pkgdir" -name '.packlist' -delete
  find "$pkgdir" -name '*.pod' -delete
}
