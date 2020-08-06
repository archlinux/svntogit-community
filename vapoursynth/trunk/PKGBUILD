# Maintainer: Maxime Gauduin <alucryd@archlinux.org>
# Contributor: sl1pkn07 <sl1pkn07@gmail.com>
# Contributor: jackoneill <cantabile.desu@gmail.com>

pkgname=vapoursynth
pkgver=R51
pkgrel=1
pkgdesc='A video processing framework with the future in mind'
arch=(x86_64)
url=http://www.vapoursynth.com/
license=(
  LGPL2.1
  custom:OFL
)
depends=(
  libass.so
  libavcodec.so
  libavformat.so
  libavutil.so
  libmagick
  libzimg.so
  python
  tesseract
)
makedepends=(
  cython
  git
  python-sphinx
)
_tag=a095cbeed3c450fe6b8b4ba68632bf12c9797b35
source=(
  git+https://github.com/vapoursynth/vapoursynth.git#tag=${_tag}
  vapoursynth.xml
)
sha256sums=(
  SKIP
  8e51579547d20cd7cb9618a47b3ac508423d09d76649bf038d0ab9acb850b068
)

pkgver() {
  cd vapoursynth

  git describe --tags
}

prepare() {
  cd vapoursynth

  sed -e 's|python-$PYTHON_VERSION|python-$PYTHON_VERSION-embed|' -i configure.ac # Fix linking with python 3.8
  ./autogen.sh
}

build() {
  cd vapoursynth

  export LDFLAGS="$LDFLAGS -lpthread"

  ./configure \
    --prefix=/usr \
    --enable-imwri \
    --disable-static
  sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool
  make
}

package() {
  cd vapoursynth

  make DESTDIR="${pkgdir}" install

  install -Dm 644 src/core/ter-116n.ofl.txt -t "${pkgdir}"/usr/share/licenses/vapoursynth/
  install -Dm 644 ../vapoursynth.xml -t "${pkgdir}"/usr/share/mime/packages/
}

# vim: ts=2 sw=2 et:
