# Contributor: Alexander Baldeck <alexander@archlinux.org>
# Maintainer: Jan de Groot <jgc@archlinux.org>

_pkgbasename=libice
pkgname=lib32-$_pkgbasename
pkgver=1.1.1
pkgrel=1
pkgdesc="X11 Inter-Client Exchange library (32-bit)"
arch=(x86_64)
url="https://xorg.freedesktop.org/"
depends=('lib32-glibc' $_pkgbasename)
makedepends=('xtrans>=1.2.5' 'xorg-util-macros' 'xorgproto')
source=(${url}/releases/individual/lib/libICE-${pkgver}.tar.xz{,.sig})
license=('custom')
sha1sums=('7e4b51bb5633d7fc7d1f4e161d231591ab545f0b'
          'SKIP')
sha256sums=('03e77afaf72942c7ac02ccebb19034e6e20f456dcf8dddadfeb572aa5ad3e451'
            'SKIP')
validpgpkeys=('3BB639E56F861FA2E86505690FDD682D974CA72A') # Matt Turner <mattst88@gmail.com>

build() {
  cd "${srcdir}/libICE-${pkgver}"

  export CC="gcc -m32"
  export PKG_CONFIG_PATH="/usr/lib32/pkgconfig"

  ./configure --prefix=/usr --sysconfdir=/etc --libdir=/usr/lib32

  make
}

package() {
  cd "${srcdir}/libICE-${pkgver}"
  make DESTDIR="${pkgdir}" install

  rm -rf "${pkgdir}"/usr/{include,share}

  mkdir -p "$pkgdir/usr/share/licenses"
  ln -s $_pkgbasename "$pkgdir/usr/share/licenses/$pkgname"
}
