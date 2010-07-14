# $Id: PKGBUILD 79801 2010-05-07 21:58:56Z ibiru $
# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Eduardo Romero <eduardo@archlinux.org>
# Contributor: Giovanni Scafora <giovanni@archlinux.org>
pkgname=wine
pkgver=1.2rc7
realver=1.2-rc7
pkgrel=1
pkgdesc="A compatibility layer for running Windows programs"
url="http://www.winehq.com"
arch=('i686')
license=('LGPL')
depends=('fontconfig' 'libxxf86dga' 'mesa' 'libxcursor' 'libxrandr' 'libxdamage')
makedepends=('cups' 'sane' 'fontforge' 'flex' 'bison' 'libgphoto2' 
             'libxinerama' 'esound' 'giflib'  'ncurses' 'libxcomposite' 
             'samba' 'libxpm' 'libxmu' 'libxxf86vm' 'perl' 'libxml2' 'jack' 
             'libxslt' 'libldap' 'lcms' 'mpg123' 'prelink')
optdepends=('cups' 'sane' 'libgphoto2' 'alsa-lib' 'giflib' 'libpng' 'jack' 
            'libldap' 'lcms' 'mpg123')
source=(http://ibiblio.org/pub/linux/system/emulators/${pkgname}/${pkgname}-${realver}.tar.bz2)
md5sums=('05cc63418e603f3d689bcaa7c7768d01')

build() {
  cd "${srcdir}/${pkgname}-${realver}"

  ./configure --prefix=/usr \
              --sysconfdir=/etc \
	      --with-x
  make depend || return 1
  make || return 1
  make prefix=${pkgdir}/usr install || return 1
  mkdir -p ${pkgdir}/etc/wine
}
