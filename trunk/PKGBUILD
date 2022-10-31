# Contributor: Jan de Groot <jgc@archlinux.org>

_pkgbasename=libxtst
pkgname=lib32-$_pkgbasename
pkgver=1.2.4
pkgrel=1
pkgdesc="X11 Testing -- Resource extension library (32-bit)"
arch=(x86_64)
url="https://xorg.freedesktop.org/"
license=('custom')
depends=('lib32-libxext' 'lib32-libxi' 'lib32-libxfixes' $_pkgbasename)
makedepends=('gcc-multilib' 'xorg-util-macros')
source=(${url}/releases/individual/lib/libXtst-${pkgver}.tar.xz{,.sig})
sha256sums=('84f5f30b9254b4ffee14b5b0940e2622153b0d3aed8286a3c5b7eeb340ca33c8'
            'SKIP')
validpgpkeys=('4A193C06D35E7C670FA4EF0BA2FB9E081F2D130E') # Alan Coopersmith <alan.coopersmith@oracle.com>

build() {
  cd "${srcdir}/libXtst-${pkgver}"

  export CC="gcc -m32"
  export PKG_CONFIG_PATH="/usr/lib32/pkgconfig"

  ./configure --prefix=/usr --disable-static \
    --libdir=/usr/lib32
  make
}

package() {
  cd "${srcdir}/libXtst-${pkgver}"

  make DESTDIR="${pkgdir}" install

  rm -rf "${pkgdir}"/usr/{include,share}

  mkdir -p "$pkgdir/usr/share/licenses"
  ln -s $_pkgbasename "$pkgdir/usr/share/licenses/$pkgname"
}
