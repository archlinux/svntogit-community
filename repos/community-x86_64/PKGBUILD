# Maintainer: Anatol Pomozov
# Contributor: 謝致邦 <Yeking@Red54.com>
# Contributor: Alucryd <alucryd at gmail dot com>

pkgname=android-tools
pkgver=33.0.3
_tag=${pkgver} # https://github.com/nmeum/android-tools sometimes carries extra patch version on top of the upstream versioning
pkgrel=1
pkgdesc='Android platform tools'
arch=(x86_64)
url='http://tools.android.com/'
license=(Apache MIT)
depends=(libusb protobuf brotli zstd android-udev pcre2)
makedepends=(gtest cmake go ninja git)
source=(https://github.com/nmeum/android-tools/releases/download/$_tag/android-tools-$_tag.tar.xz)
sha256sums=('8ce174dab781d5debd29ed0f96572231f777bee19b8ef3c167e33d3ea7670bc5')

build() {
  cd android-tools-$_tag

  cmake \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_CXX_FLAGS="$CXXFLAGS" \
    -DCMAKE_C_FLAGS="$CFLAGS" \
    -G Ninja -S . -B build
}

package() {
  cd android-tools-$_tag

  DESTDIR="${pkgdir}" ninja -C build install
}
