# Maintainer: Jaroslav Lichtblau <svetlemodry@archlinux.org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: David Dent <thewinch@gmail.com>
# Contributor: orbisvicis <orbisvicis@gmail.com>

pkgname=mapnik
pkgver=3.0.21
pkgrel=4
pkgdesc="Free Toolkit for developing mapping applications and rendering beautiful maps"
arch=('x86_64')
url="http://mapnik.org/"
license=('LGPL')
depends=('boost-libs' 'icu' 'libpng' 'libjpeg-turbo' 'libtiff' 'freetype2'
         'libxml2' 'python2' 'proj' 'cairo' 'cairomm' 'python2-cairo'
         'postgresql-libs' 'postgis' 'gdal' 'curl' 'libtool' 'libwebp')
makedepends=('scons' 'boost' 'git' 'patch')
optdepends=('libxslt:         Web Map Service'
            'python2-lxml:    Web Map Service'
            'python2-pillow:  Web Map Service'
            'python-nose:     Web Map Service'
            'apache:          Web Map Service'
            'mod_fcgid:       Web Map Service - or:'
            'mod_wsgi2:       Web Map Service')
install=$pkgname.install
source=(https://github.com/$pkgname/$pkgname/releases/download/v$pkgver/$pkgname-v$pkgver.tar.bz2
        https://github.com/mapnik/mapnik/pull/3892.patch
        mapnik-boost-1.68.patch::https://github.com/mapnik/mapnik/pull/3937.patch
        mapnik-boost-1.69.patch::https://github.com/mapnik/mapnik/commit/bcb1e67507.patch)
sha256sums=('6db7918e8fd24346dfc81745e455c383a718335ffa64015cf625fed5ed92b524'
            '774a8590b698e9dc2a483e6ff48781ed0400ba06b901f12a1ed50c9114833d47'
            '6b1eb2a013e3e83190cb833cfed370dbe03bd009b51f909112bc353fca7ee4e7'
            'c47d8bdf6ccfe72b459f0898a3a92eb044d2b1a9b92f208db9ffcb4c173bdf31')

prepare() {
  cd "${srcdir}"/$pkgname-v$pkgver
  patch -Np1 -i "${srcdir}"/3892.patch
  patch -p1 -i ../mapnik-boost-1.68.patch # Fix build with boost 1.68
  patch -p1 -i ../mapnik-boost-1.69.patch # Fix build with boost 1.69
}

build() {
  cd "${srcdir}"/$pkgname-v$pkgver

  # http://site.icu-project.org/download/61#TOC-Migration-Issues
  CXXFLAGS+=' -DU_USING_ICU_NAMESPACE=1'

  PYTHON=python2
  scons configure \
    PREFIX="/usr" \
    INPUT_PLUGINS=all \
    XMLPARSER=libxml2 \
    DESTDIR="$pkgdir" \
    CUSTOM_CXXFLAGS="$CXXFLAGS" \
    CUSTOM_LDFLAGS="$LDFLAGS"
  scons $(expr "$MAKEFLAGS" : '.*\(\-j[0-9]\+\)')
}

package(){
  cd "${srcdir}"/$pkgname-v$pkgver
  scons install
}
