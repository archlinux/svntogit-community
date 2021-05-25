# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: Jorge Araya Navarro <jorgejavieran@yahoo.com.mx>
# Contributor: Cristian Porras <porrascristian@gmail.com>
# Contributor: Matthew Bentley <matthew@mtbentley.us>

pkgname=godot
pkgver=3.3.2
pkgrel=1
pkgdesc='Advanced cross-platform 2D and 3D game engine'
url='https://godotengine.org'
license=(MIT)
arch=(x86_64)
makedepends=(gcc scons yasm)
depends=(alsa-lib freetype2 libglvnd libxcursor libxinerama libxrandr pulseaudio)
source=("$pkgname-$pkgver.tar.gz::https://github.com/godotengine/godot/archive/$pkgver-stable.tar.gz")
b2sums=('1d7ee1703388d98c41524f64a99859216b060daad4502c4118adf31a95d45aa230d058630ae8735282a9b5d9f7c1ee464fb4caf9f92e3e55340370e007102f8d')

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
