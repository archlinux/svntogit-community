# Maintainer: Anatol Pomozov
# Contributor: 謝致邦 <Yeking@Red54.com>
# Contributor: Alucryd <alucryd at gmail dot com>

pkgname=android-tools
pkgver=31.0.0
_tag=${pkgver}p1 # https://github.com/nmeum/android-tools sometimes carries extra patch version on top of the upstream versioning
pkgrel=3
pkgdesc='Android platform tools'
arch=(x86_64)
url='http://tools.android.com/'
license=(Apache MIT)
depends=(libusb protobuf brotli zstd android-udev)
makedepends=(pcre2 gtest cmake go ninja git)
source=(https://github.com/nmeum/android-tools/releases/download/$_tag/android-tools-$_tag.tar.xz
        android-tools-gcc11.patch)
sha256sums=('51a4c3ba5f16945905449c4bd2c1c781a4df7469f6b7362f8837f4f640d8c7b6'
            '75fd8517769e5cb3b9a4b54c7d2d0b728537e35a42113531e8b7dfb6f296ea84')

prepare() {
  cd android-tools-$_tag
  patch -d vendor/boringssl -p1 < ../android-tools-gcc11.patch
}

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
