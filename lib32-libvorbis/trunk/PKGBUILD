
pkgname=lib32-libvorbis
pkgver=1.3.7
pkgrel=1
pkgdesc='Vorbis codec library (32-bit)'
arch=('x86_64')
url='https://www.xiph.org/ogg/vorbis/'
license=('BSD')
depends=('lib32-libogg' 'libvorbis')
provides=('libvorbis.so' 'libvorbisenc.so' 'libvorbisfile.so')
source=("https://downloads.xiph.org/releases/vorbis/libvorbis-${pkgver}.tar.gz")
sha256sums=('0e982409a9c3fc82ee06e08205b1355e5c6aa4c36bca58146ef399621b0ce5ab')

build() {
  cd libvorbis-${pkgver}

  export CC="gcc -m32"
  export CXX="g++ -m32"
  export PKG_CONFIG="i686-pc-linux-gnu-pkg-config"

  ./configure \
    --prefix='/usr' \
    --libdir='/usr/lib32' \
    --disable-static
  make
}

check() {
  cd libvorbis-${pkgver}

  make -j1 check
}

package() {
  cd libvorbis-${pkgver}

  make DESTDIR="${pkgdir}" install

  rm -rf "${pkgdir}"/usr/{include,share,bin}
  install -d "$pkgdir/usr/share/licenses"
  ln -s libvorbis "$pkgdir/usr/share/licenses/$pkgname"
}

# vim: ts=2 sw=2 et:
