# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: Aleksandar Trifunović <akstrfn@gmail.com>
# Contributor: Iván Ruvalcaba <mario.i.ruvalcaba@gmail.com>
# Contributor: Ian Ker-Seymer <i.kerseymer@gmail.com>

pkgname=neovim-qt
pkgver=0.2.17
pkgrel=2
pkgdesc='GUI for Neovim'
arch=(x86_64)
url='https://github.com/equalsraf/neovim-qt'
license=(ISC)
depends=(neovim qt5-svg hicolor-icon-theme)
makedepends=(cmake git ninja)
checkdepends=(ttf-dejavu xorg-server-xvfb)
source=("git+$url#commit=3f05de82ecb5c1a24a7572081ae59e419eb059b8") # tag: v0.2.17
b2sums=('SKIP')

build() {
  cmake \
    -B build \
    -D CMAKE_BUILD_TYPE=Release \
    -D CMAKE_C_FLAGS="$CFLAGS" \
    -D CMAKE_CXX_FLAGS="$CXXFLAGS" \
    -D CMAKE_EXE_LINKER_FLAGS="$LDFLAGS" \
    -D CMAKE_INSTALL_LIBDIR=lib \
    -D CMAKE_INSTALL_PREFIX=/usr \
    -D USE_SYSTEM_MSGPACK=on \
    -G Ninja \
    -S $pkgname
  ninja -C build
}

check() {
  xvfb-run ninja -v -C build test
}

package() {
  DESTDIR="$pkgdir" ninja -C build install
  install -Dm644 -t "$pkgdir/usr/share/licenses/$pkgname" "$pkgname/LICENSE"
}
