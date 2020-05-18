# Maintainer: Thore Bödecker <foxxx0@archlinux.org>
# Contributor: Giovanni Scafora <giovanni@archlinux.org>
# Contributor: François Charette <firmicus ατ gmx δοτ net>

pkgname=perl-io-stringy
_pkgname='IO-Stringy'
pkgver=2.113
pkgrel=1
pkgdesc="I/O on in-core objects like strings/arrays"
arch=('any')
url="https://metacpan.org/pod/IO::Stringy"
license=('GPL' 'PerlArtistic')
depends=('perl')
options=('!emptydirs')
source=("https://cpan.metacpan.org/authors/id/C/CA/CAPOEIRAB/${_pkgname}-${pkgver}.tar.gz")
sha512sums=('5af104766c20b4336649dc4a19554ad204506c2476b4bf7d8ad7c2cfab15f0296efadb9019cd57e770a2a3c5f5686f7f010bddbd6efd51d300c54ca36286f094')

build() {
  cd  "${srcdir}/${_pkgname}-${pkgver}"
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd  "${srcdir}/${_pkgname}-${pkgver}"
  make test
}

package() {
  cd  "${srcdir}/${_pkgname}-${pkgver}"
  make install DESTDIR="${pkgdir}"

  find "${pkgdir}" -name '.packlist' -delete
  find "${pkgdir}" -name '*.pod' -delete
}
