# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: loqs
# Contributor: Jorge Araya Navarro <jorgejavieran@yahoo.com.mx>
# Contributor: Cristian Porras <porrascristian@gmail.com>
# Contributor: Matthew Bentley <matthew@mtbentley.us>

pkgname=godot
pkgver=3.3.4
pkgrel=3
pkgdesc='Advanced cross-platform 2D and 3D game engine'
url='https://godotengine.org'
license=(MIT)
arch=(x86_64)
makedepends=(gcc scons yasm alsa-lib pulseaudio)
depends=(bullet embree freetype2 libglvnd libtheora libvorbis libvpx libwebp
         libwslay libxcursor libxi libxinerama libxrandr mbedtls miniupnpc opusfile)
optdepends=(alsa-lib pulseaudio)
source=("$pkgname-$pkgver.tar.gz::https://github.com/godotengine/godot/archive/$pkgver-stable.tar.gz")
b2sums=('27536d0e98fcd4b30b76154f03e68398db69fdf2da81c71adef78b04e884f00104c9213110dd95fdb61ad7f2496f765e071362a1c951b20b6e6f03f4dc718c1e')

prepare() {
  # Disable the check that adds -no-pie to LINKFLAGS, for gcc != 6
  sed -i 's,0] >,0] =,g' $pkgname-$pkgver-stable/platform/x11/detect.py
}

build() {
  # Not unbundled yet:
  #  enet (contains no upstreamed IPv6 support)
  #  libsquish, recast, xatlas
  #  AUR: libwebm, squish
  local to_unbundle="bullet certs embree freetype libogg libpng libtheora libvorbis libvpx libwebp mbedtls miniupnpc opus pcre2 wslay zlib zstd"
  local system_libs=""
  for _lib in $to_unbundle; do
    system_libs+="builtin_"$_lib"=no "
    rm -rf thirdparty/$_lib
  done

  cd $pkgname-$pkgver-stable
  export BUILD_NAME=arch_linux
  scons -j16 \
    system_certs_path=/etc/ssl/certs/ca-certificates.crt \
    bits=64 \
    colored=yes \
    platform=x11 \
    pulseaudio=yes \
    target=release_debug \
    tools=yes \
    use_llvm=no \
    CFLAGS="$CFLAGS -fPIC -Wl,-z,relro,-z,now" \
    CXXFLAGS="$CXXFLAGS -fPIC -Wl,-z,relro,-z,now" \
    LINKFLAGS="$LDFLAGS" \
    $system_libs
}

package() {
  cd $pkgname-$pkgver-stable
  install -Dm644 misc/dist/linux/org.godotengine.Godot.desktop "$pkgdir/usr/share/applications/godot.desktop"
  install -Dm644 icon.svg "$pkgdir/usr/share/pixmaps/godot.svg"
  install -Dm755 bin/godot.x11.opt.tools.64 "$pkgdir/usr/bin/$pkgname"
  install -Dm644 LICENSE.txt "$pkgdir/usr/share/licenses/godot/LICENSE"
  install -Dm644 misc/dist/linux/godot.6 "$pkgdir/usr/share/man/man6/godot.6"
}
