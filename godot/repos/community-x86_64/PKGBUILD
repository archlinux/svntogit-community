# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: Jorge Araya Navarro <jorgejavieran@yahoo.com.mx>
# Contributor: Cristian Porras <porrascristian@gmail.com>
# Contributor: Matthew Bentley <matthew@mtbentley.us>

pkgname=godot
pkgver=3.3
pkgrel=1
pkgdesc='Advanced cross-platform 2D and 3D game engine'
url='https://godotengine.org'
license=(MIT)
arch=(x86_64)
makedepends=(gcc scons yasm)
depends=(alsa-lib freetype2 libglvnd libxcursor libxinerama libxrandr pulseaudio)
source=("$pkgname-$pkgver.tar.gz::https://github.com/godotengine/godot/archive/$pkgver-stable.tar.gz")
b2sums=('280b3b371c96e7a39e23f843759754e932fe4fd62b774b5d2d0d0e687fdb5dc8be7d95a18465f52d6f00456f62451115b1bf2e4afc2923ce704ffcde0f06544d')

build() {
  cd $pkgname-$pkgver-stable
  export BUILD_NAME=arch_linux
  scons -j12 \
    bits=64 \
    colored=yes \
    platform=x11 \
    pulseaudio=yes \
    target=release_debug \
    tools=yes \
    use_llvm=no \
    CFLAGS="$CFLAGS -Wl,-z,relro,-z-now -w" \
    CXXFLAGS="$CXXFLAGS -Wl,-z,relro,-z-now -w" \
    LINKFLAGS="$LDFLAGS -Wl,-z,relro,-z-now -w"
}

package() {
  cd $pkgname-$pkgver-stable
  install -Dm644 misc/dist/linux/org.godotengine.Godot.desktop "$pkgdir/usr/share/applications/godot.desktop"
  install -Dm644 icon.svg "$pkgdir/usr/share/pixmaps/godot.svg"
  install -Dm755 bin/godot.x11.opt.tools.64 "$pkgdir/usr/bin/$pkgname"
  install -Dm644 LICENSE.txt "$pkgdir/usr/share/licenses/godot/LICENSE"
  install -Dm644 misc/dist/linux/godot.6 "$pkgdir/usr/share/man/man6/godot.6"
}
