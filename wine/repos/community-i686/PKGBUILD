# $Id: PKGBUILD 79801 2010-05-07 21:58:56Z ibiru $
# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Eduardo Romero <eduardo@archlinux.org>
# Contributor: Giovanni Scafora <giovanni@archlinux.org>
pkgname=wine
pkgver=1.2
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
source=(http://ibiblio.org/pub/linux/system/emulators/${pkgname}/${pkgname}-${pkgver}.tar.bz2)
md5sums=('eb4e5423b277fc1e77807b04f366f7b7')

build() {
  cd "${srcdir}/${pkgname}-${pkgver}"

  ./configure --prefix=/usr \
              --sysconfdir=/etc \
	      --with-x
  make depend || return 1
  make || return 1
  make prefix=${pkgdir}/usr install || return 1
  mkdir -p ${pkgdir}/etc/wine
}
