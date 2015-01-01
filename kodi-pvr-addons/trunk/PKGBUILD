# $Id
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-pvr-addons
pkgver=20141212
_relname='Helix_rc3'
pkgrel=1
pkgdesc="PVR add-ons for current stable kodi"
arch=('i686' 'x86_64')
url="https://github.com/opdenkamp/xbmc-pvr-addons"
license=('GPL3')
depends=('kodi')
makedepends=('git' 'libmysqlclient' 'boost')
optdepends=('tvheadend-git: tvheadend backend' 'mythtv: mythtv backend')
replaces=('xbmc-pvr-addons')
conflicts=('xbmc-pvr-addons' 'xbmc-pvr-addons-git')
source=("$pkgname-$pkgver.tar.gz::https://github.com/opdenkamp/xbmc-pvr-addons/archive/${_relname}.tar.gz")

build() {
  cd "$srcdir/xbmc-pvr-addons-${_relname}"
  ./bootstrap
  ./configure --prefix=/usr --enable-addons-with-dependencies
  make
}

package() {
  cd "$srcdir/xbmc-pvr-addons-${_relname}"
  make DESTDIR="$pkgdir/" install
}

sha256sums=('e48de53c58245e512095d515d463f013e51e165fc617f1cb93e443cdd9f5096b')
