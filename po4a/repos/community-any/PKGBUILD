# Maintainer: Jaroslav Lichtblau <svetlemodry@archlinux.org>
# Contributor: Thorsten Töpper <atsutane-tu@freethoughts.de>
# Contributor: Francois Boulogne <fboulogne at april dot org>
# Contributor: Andre Klitzing <aklitzing () online () de>
# Contributor: Allan McRae <mcrae_allan@hotmail.com>
# Contributor: Mikko Seppälä <t-r-a-y@mbnet.fi> aka Neverth

pkgname=po4a
pkgver=0.56
pkgrel=1
pkgdesc="Tools for helping translation of documentation"
arch=('any')
url="https://po4a.org/"
license=('GPL')
depends=('perl' 'gettext')
makedepends=('docbook-xsl' 'perl-text-wrapi18n' 'perl-locale-gettext'
             'perl-term-readkey' 'perl-sgmls' 'perl-module-build' 'perl-unicode-linebreak')
options=('!emptydirs')
source=($pkgname-$pkgver.tar.gz::https://github.com/mquinson/$pkgname/archive/v$pkgver.tar.gz)
sha256sums=('f5a4fbf17a98a72d0490e004ba373ea2825091c65748f32425413dee6dfe0ea2')

build() {
  cd ${pkgname}-${pkgver}
  perl Build.PL installdirs=vendor create_packlist=0
  # The script expects a UTF-8 locale
  LC_ALL=en_US.UTF-8 perl Build
}

package() {
  cd ${pkgname}-${pkgver}
  perl Build destdir="${pkgdir}" install
  # remove perllocal.pod and .packlist
  find "${pkgdir}" -name .packlist -o -name perllocal.pod -delete
}
