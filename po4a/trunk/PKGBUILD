# $Id
# Maintainer: Thorsten Töpper <atsutane-tu@freethoughts.de>
# Contributor: Francois Boulogne <fboulogne at april dot org>
# Contributor: Andre Klitzing <aklitzing () online () de>
# Contributor : Allan McRae <mcrae_allan@hotmail.com>
# Contributor: Mikko Seppälä <t-r-a-y@mbnet.fi> aka Neverth

pkgname=po4a
pkgver=0.40.1
pkgrel=1
pkgdesc="po4a - tools for helping translation of documentation"
arch=('i686' 'x86_64')
license=('GPL')
url="http://po4a.alioth.debian.org/"
depends=('perl' 'gettext')
makedepends=('docbook-xsl' 'perl-text-wrapi18n' 'perl-module-build' 'perl-locale-gettext' 'perl-term-readkey' 'perl-sgmls')
options=('!emptydirs')
source=("https://alioth.debian.org/frs/download.php/3341/${pkgname}-v${pkgver}.tar.gz")
md5sums=('669cb97bf9d7ef8ff4fb7af13124bfcb')

build()
{
  cd "${srcdir}/${pkgname}-v${pkgver}"
  perl Build.PL
  perl Build
  LANG=en_US.UTF-8 make
}

package() {
  cd "${srcdir}/${pkgname}-v${pkgver}"

  make install DESTDIR="${pkgdir}" prefix="/usr"
}

