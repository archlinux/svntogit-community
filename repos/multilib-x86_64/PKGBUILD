# Maintainer: Florian Pritz <bluewind@xinu.at>

_pkgbasename=harfbuzz
pkgname=lib32-$_pkgbasename
pkgver=0.9.32
pkgrel=1
pkgdesc="OpenType text shaping engine. (32-bit)"
arch=('x86_64')
url="http://www.freedesktop.org/wiki/Software/HarfBuzz"
license=('MIT')
depends=('lib32-icu' 'lib32-glib2' 'lib32-freetype2' $_pkgbasename)
makedepends=('gcc-multilib')
source=(http://www.freedesktop.org/software/harfbuzz/release/${_pkgbasename}-${pkgver}.tar.bz2)
sha256sums=('430c81744e2d87b36f529b16f18efd0d0140aee9df59b2ee312f5de1994b9db4')

build() {
  export CC="gcc -m32"
  export CXX="g++ -m32"
  export PKG_CONFIG_PATH="/usr/lib32/pkgconfig"

  cd "${srcdir}/${_pkgbasename}-${pkgver}"

  # work around autogen.sh requiring ragel
  autoreconf --force --install --verbose
  ./configure --prefix=/usr --libdir=/usr/lib32 --disable-silent-rules --with-graphite2=no --without-cairo
  make
}

package() {
  cd "${srcdir}/${_pkgbasename}-${pkgver}"

  make DESTDIR="${pkgdir}" install

  rm -rf "${pkgdir}"/usr/{include,share,bin}
  mkdir -p "$pkgdir/usr/share/licenses"
  ln -s $_pkgbasename "$pkgdir/usr/share/licenses/$pkgname"
}
