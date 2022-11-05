# Maintainer : Ionut Biru <ibiru@archlinux.org>

_pkgbasename=pixman
pkgname=lib32-$_pkgbasename
pkgver=0.42.2
pkgrel=1
pkgdesc="Pixman library (32-bit)"
arch=('x86_64')
url="https://xorg.freedesktop.org"
license=('custom')
depends=('lib32-glibc' $_pkgbasename)
makedepends=('gcc-multilib')
source=(https://xorg.freedesktop.org/releases/individual/lib/${_pkgbasename}-${pkgver}.tar.xz)
sha512sums=('3476e2676e66756b1af61b1e532cd80c985c191fb7956eb01702b419726cce99e79163b7f287f74f66414680e7396d13c3fee525cd663f12b6ac4877070ff4e8')

build() {
  export CC="gcc -m32"
  export CXX="g++ -m32"
  export PKG_CONFIG_PATH="/usr/lib32/pkgconfig"

  cd "${srcdir}/${_pkgbasename}-${pkgver}"
  ./configure --prefix=/usr --libdir=/usr/lib32 --disable-static
  make
}

package() {
  cd "${srcdir}/${_pkgbasename}-${pkgver}"
  make DESTDIR="${pkgdir}" install
  rm -rf "${pkgdir}"/usr/include
  mkdir -p "$pkgdir/usr/share/licenses"
  ln -s $_pkgbasename "$pkgdir/usr/share/licenses/$pkgname"
}
