# Maintainer: Anatol Pomozov
# Contributor: 謝致邦 <Yeking@Red54.com>
# Contributor: Alucryd <alucryd at gmail dot com>

pkgname=android-tools
pkgver=30.0.5
_tag=${pkgver}p1 # https://github.com/nmeum/android-tools carries extra patch version on top of the upstream versioning
pkgrel=3
pkgdesc='Android platform tools'
arch=(x86_64)
url='http://tools.android.com/'
license=(Apache MIT)
depends=(libusb protobuf brotli zstd)
makedepends=(pcre2 gtest cmake go ninja)
source=(https://github.com/nmeum/android-tools/releases/download/$_tag/android-tools-$_tag.tar.xz
        bash_completion.fastboot)
        # Bash completion file was taken from https://github.com/mbrubeck/android-completion
sha256sums=('8400387db0ff3c7d030418b9f63ea171917c26e6bcc82d9dc666c8c4c02e9806'
            '0807281422825404a7bee2a76f89062a104777011530f7c5e559910b8e585b0a')

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
  install -Dm 644 ../bash_completion.fastboot "$pkgdir"/usr/share/bash-completion/completions/fastboot
}
