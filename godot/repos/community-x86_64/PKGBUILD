# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: Jorge Araya Navarro <jorgejavieran@yahoo.com.mx>
# Contributor: Cristian Porras <porrascristian@gmail.com>
# Contributor: Matthew Bentley <matthew@mtbentley.us>

pkgname=godot
pkgver=3.2.3
pkgrel=1
pkgdesc='Advanced cross-platform 2D and 3D game engine'
url='https://godotengine.org'
license=(MIT)
arch=(x86_64)
makedepends=(gcc scons yasm)
depends=(alsa-lib freetype2 libglvnd libxcursor libxi libxinerama libxrandr pulseaudio)
source=("$pkgname-$pkgver.tar.gz::https://github.com/godotengine/godot/archive/$pkgver-stable.tar.gz")
sha256sums=('4c2a8e7da1ad05c6223b0ff6cf2be124dad6708b56a8ec9910dc2aaf82a553ae')

build() {
  cd $pkgname-$pkgver-stable
  scons -j12 \
    bits=64 \
    colored=yes \
    platform=x11 \
    pulseaudio=yes \
    target=release_debug \
    tools=yes \
    use_llvm=no
}

package() {
  cd $pkgname-$pkgver-stable
  install -Dm644 misc/dist/linux/org.godotengine.Godot.desktop "$pkgdir/usr/share/applications/godot.desktop"
  install -Dm644 icon.svg "$pkgdir/usr/share/pixmaps/godot.svg"
  install -Dm755 bin/godot.x11.opt.tools.64 "$pkgdir/usr/bin/$pkgname"
  install -Dm644 LICENSE.txt "$pkgdir/usr/share/licenses/godot/LICENSE"
  install -Dm644 misc/dist/linux/godot.6 "$pkgdir/usr/share/man/man6/godot.6"
}
