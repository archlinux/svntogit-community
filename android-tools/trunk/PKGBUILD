# Maintainer: Anatol Pomozov
# Contributor: 謝致邦 <Yeking@Red54.com>
# Contributor: Alucryd <alucryd at gmail dot com>

pkgname=android-tools
pkgver=31.0.3
_tag=${pkgver}p1 # https://github.com/nmeum/android-tools sometimes carries extra patch version on top of the upstream versioning
pkgrel=6
pkgdesc='Android platform tools'
arch=(x86_64)
url='http://tools.android.com/'
license=(Apache MIT)
depends=(libusb protobuf brotli zstd android-udev)
makedepends=(pcre2 gtest cmake go ninja git)
source=(https://github.com/nmeum/android-tools/releases/download/$_tag/android-tools-$_tag.tar.xz        gcc12.patch)
sha256sums=('0ef69f919d58a2bdff2083d2e83a9ef38df079ec82651b2544e9e48086df5ab8'
            'df27d803da03d0a2656c4feb3cf471a076c459f45004ec20ec86a5cfb36be862')

prepare() {
  cd android-tools-$_tag
  patch -Np1 -i ../gcc12.patch
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
