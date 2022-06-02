# Maintainer: Justin Davis <jrcd83@gmail.com>
# Contributor: François Charette <firmicus ατ gmx δοτ net>

pkgname=perl-xml-writer
pkgver=0.900
pkgrel=1
pkgdesc="Module for writing XML documents"
arch=('any')
url="https://search.cpan.org/dist/XML-Writer"
license=('custom')
depends=('perl')
options=('!emptydirs')
source=(https://www.cpan.org/authors/id/J/JO/JOSEPHW/XML-Writer-$pkgver.tar.gz)
sha256sums=('73c8f5bd3ecf2b350f4adae6d6676d52e08ecc2d7df4a9f089fa68360d400d1f')

build() {
  cd XML-Writer-$pkgver
  perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd XML-Writer-$pkgver
  make test
}

package() {
  cd  XML-Writer-$pkgver
  make DESTDIR="${pkgdir}" install
  install -D -m644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
