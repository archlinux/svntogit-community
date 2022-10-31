# Contributor: Jan de Groot <jgc@archlinux.org>

_pkgbasename=libxxf86vm
pkgname=lib32-$_pkgbasename
pkgver=1.1.5
pkgrel=1
pkgdesc="X11 XFree86 video mode extension library (32-bit)"
arch=('x86_64')
license=('custom')
url="https://xorg.freedesktop.org/"
depends=('lib32-libxext' $_pkgbasename)
makedepends=('xorg-util-macros' gcc-multilib)
source=(${url}/releases/individual/lib/libXxf86vm-${pkgver}.tar.xz{,.sig})
sha512sums=('68226fcb9773a583ea417ab413146203dd7db6ff8a4d388285da972353355e11e179861a77c9fa284aefac025bb3bbf5a9537fa0bf246c782e0116a667c9d9b6'
            'SKIP')
validpgpkeys=('4A193C06D35E7C670FA4EF0BA2FB9E081F2D130E') # Alan Coopersmith <alan.coopersmith@oracle.com>

build() {
  export CC="gcc -m32"
  export CXX="g++ -m32"
  export PKG_CONFIG_PATH="/usr/lib32/pkgconfig"

  cd "${srcdir}/libXxf86vm-${pkgver}"
  ./configure --prefix=/usr --disable-static \
    --libdir=/usr/lib32
  make
}

package() {
  cd "${srcdir}/libXxf86vm-${pkgver}"

  make DESTDIR="${pkgdir}" install

  rm -rf "${pkgdir}"/usr/{include,share,bin}
  mkdir -p "$pkgdir/usr/share/licenses"
  ln -s $_pkgbasename "$pkgdir/usr/share/licenses/$pkgname"
}
