# Contributor: Jan de Groot <jgc@archlinux.org>

_pkgbasename=libxv
pkgname=lib32-$_pkgbasename
pkgver=1.0.12
pkgrel=1
pkgdesc="X11 Video extension library (32-bit)"
arch=('x86_64')
license=('custom')
url="https://xorg.freedesktop.org/"
depends=('lib32-libxext' $_pkgbasename)
makedepends=('pkgconfig' gcc-multilib)
source=(${url}/releases/individual/lib/libXv-${pkgver}.tar.xz{,.sig})
sha256sums=('aaf7fa09f689f7a2000fe493c0d64d1487a1210db154053e9e2336b860c63848'
            'SKIP')
validpgpkeys+=('4A193C06D35E7C670FA4EF0BA2FB9E081F2D130E') # "Alan Coopersmith <alan.coopersmith@oracle.com>"

build() {
  export CC="gcc -m32"
  export CXX="g++ -m32"
  export PKG_CONFIG_PATH="/usr/lib32/pkgconfig"

  cd "${srcdir}/libXv-${pkgver}"
  ./configure --prefix=/usr --disable-static \
    --libdir=/usr/lib32
  make
}

package() {
  cd "${srcdir}/libXv-${pkgver}"

  make DESTDIR="${pkgdir}" install

  rm -rf "${pkgdir}"/usr/{include,share,bin}
  mkdir -p "$pkgdir/usr/share/licenses"
  ln -s $_pkgbasename "$pkgdir/usr/share/licenses/$pkgname"
}
