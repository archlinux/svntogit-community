# Contributor: Jan de Groot <jgc@archlinux.org>

_pkgbasename=libxmu
pkgname=lib32-$_pkgbasename
pkgver=1.1.4
pkgrel=1
pkgdesc="X11 miscellaneous micro-utility library (32-bit)"
arch=('x86_64')
url="https://xorg.freedesktop.org/"
depends=('lib32-libxext' 'lib32-libxt' $_pkgbasename)
makedepends=('xorg-util-macros' 'gcc-multilib')
license=('custom')
source=(${url}/releases/individual/lib/libXmu-${pkgver}.tar.xz{,.sig})
sha512sums=('3cf90cb3ff380aafefbb39297bdd95b9e1e6d6618cecb53ff09faf38f9b9c54599d28367f07a9ec77a20214c6c3e661b8d0a12b38082556790a79a59942039c1'
            'SKIP')
validpgpkeys=('4A193C06D35E7C670FA4EF0BA2FB9E081F2D130E') # Alan Coopersmith <alan.coopersmith@oracle.com>

build() {
  cd "${srcdir}/libXmu-${pkgver}"

  export CC="gcc -m32"
  export PKG_CONFIG_PATH="/usr/lib32/pkgconfig"

  ./configure --prefix=/usr --sysconfdir=/etc --disable-static \
    --libdir=/usr/lib32
  make
}

package() {
  cd "${srcdir}/libXmu-${pkgver}"

  make DESTDIR="${pkgdir}" install

  rm -rf "${pkgdir}"/usr/{include,share}

  mkdir -p "$pkgdir/usr/share/licenses"
  ln -s $_pkgbasename "$pkgdir/usr/share/licenses/$pkgname" 
}
