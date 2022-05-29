# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

pkgname=perl-sub-override
_cpanname=Sub-Override
pkgver=0.09
pkgrel=4
pkgdesc='Perl extension for easily overriding subroutines'
url='https://search.cpan.org/dist/Term-ExtendedColor'
arch=('any')
license=('PerlArtistic' 'GPL')
depends=('perl')
checkdepends=('perl-test-fatal')
options=('!emptydirs')
source=(https://search.cpan.org/CPAN/authors/id/O/OV/OVID/${_cpanname}-${pkgver}.tar.gz)
sha512sums=('35000e8cabb6ca4cc0cac53af99fc9cb8ac14b1e71dbfa27dc58a339cb1b54e439064f2241798e351cc5ad297a2f9e4fde870ca97e2eb09a2430c11af589d412')
b2sums=('27345159d3475c30c40852fa93db246c91b4d83806154adefcde907ff42ac0726d9c84880735a148acb6ce929a14c43d30287dd71307e41667841bf25db3bb99')

build() {
  cd ${_cpanname}-${pkgver}
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

check() {
  cd ${_cpanname}-${pkgver}
  make test
}

package() {
  cd ${_cpanname}-${pkgver}
  make DESTDIR="${pkgdir}" install
  install -Dm 644 README* -t "${pkgdir}/usr/share/doc/${pkgname}"
}

# vim: ts=2 sw=2 et:
