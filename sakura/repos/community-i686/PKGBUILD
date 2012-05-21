# $Id$
# Maintainer: Ronald van Haren <ronald.archlinux.org>
# Contributor: Dmitry N. Shilov <stormblast@land.ru>

pkgname=sakura
pkgver=3.0.4
pkgrel=1
pkgdesc="A terminal emulator based on GTK and VTE"
arch=('i686' 'x86_64')
url="https://launchpad.net/sakura"
license=('GPL')
depends=('vte3' 'libxft' 'desktop-file-utils')
makedepends=('cmake')
source=("https://launchpad.net/sakura/trunk/${pkgver}/+download/${pkgname}-${pkgver}.tar.bz2")
install=sakura.install
sha1sums=('e4d3a7fce9600cbdec9fda1e6fd20f38ebb4655e')

build() {
  cd $srcdir/${pkgname}-${pkgver}

  # Set default font size a bit smaller
  sed -i 's|#define DEFAULT_FONT "Bitstream Vera Sans Mono 14"|#define DEFAULT_FONT "Bitstream Vera Sans Mono 10"|g' src/sakura.c
 
  # build & install	
  cmake -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=RELEASE . 
  make 
}

package() {
  cd $srcdir/${pkgname}-${pkgver}

  make DESTDIR=${pkgdir} install 
  # extract the keybindings from the installed documentation, rest is only relevant during build time
  awk '/^Keybindings/{f="'${pkgdir}'/usr/share/doc/'${pkgname}'/KEYBINDINGS"} f{print > f} /^END/' \
        ${pkgdir}/usr/share/doc/${pkgname}/INSTALL
  rm ${pkgdir}/usr/share/doc/${pkgname}/INSTALL
}

