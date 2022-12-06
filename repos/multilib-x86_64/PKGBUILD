# Contributor: Jan de Groot <jgc@archlinux.org>

_pkgbasename=libxdmcp
pkgname=lib32-$_pkgbasename
pkgver=1.1.4
pkgrel=1
pkgdesc="X11 Display Manager Control Protocol library (32-bit)"
arch=(x86_64)
url="https://xorg.freedesktop.org/"
license=('custom')
depends=('lib32-glibc' $_pkgbasename)
makedepends=('xorg-util-macros' 'xorgproto')
provides=('libXdmcp.so')
options=('debug')
source=(${url}/releases/individual/lib/libXdmcp-${pkgver}.tar.xz{,.sig})
sha512sums=('83b384d43bfb034c395f83f97d1c6e73aa3d5faa8f8756b08e697c0b9c3c87189651b51e8213fbd1f5f9cbc2d8136cbf143627481744345d78cfe0ff2ad074a9'
            'SKIP')
validpgpkeys=('4A193C06D35E7C670FA4EF0BA2FB9E081F2D130E') # Alan Coopersmith <alan.coopersmith@oracle.com>

build() {
  cd libXdmcp-${pkgver}

  export CC="gcc -m32"
  export PKG_CONFIG="i686-pc-linux-gnu-pkg-config"

  ./configure --prefix=/usr --sysconfdir=/etc --disable-static \
              --libdir=/usr/lib32
  make
}

package() {
  cd libXdmcp-${pkgver}

  make DESTDIR="${pkgdir}" install

  rm -rf "${pkgdir}"/usr/{include,share}

  mkdir -p "$pkgdir/usr/share/licenses"
  ln -s $_pkgbasename "$pkgdir/usr/share/licenses/$pkgname" 
}
