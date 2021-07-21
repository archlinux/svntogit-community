# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: loqs
# Contributor: Jorge Araya Navarro <jorgejavieran@yahoo.com.mx>
# Contributor: Cristian Porras <porrascristian@gmail.com>
# Contributor: Matthew Bentley <matthew@mtbentley.us>

pkgname=godot
pkgver=3.3.2
pkgrel=2
pkgdesc='Advanced cross-platform 2D and 3D game engine'
url='https://godotengine.org'
license=(MIT)
arch=(x86_64)
makedepends=(gcc scons yasm alsa-lib pulseaudio)
depends=(bullet embree freetype2 libglvnd libogg libpng libtheora libvorbis
         libvpx libwebp libxcursor libxi libxinerama libxrandr mbedtls
         miniupnpc opus opusfile pcre2 zlib zstd)
optdepends=(alsa-lib pulseaudio)
source=("$pkgname-$pkgver.tar.gz::https://github.com/godotengine/godot/archive/$pkgver-stable.tar.gz"
         06c42d151cf7b70b73dda42eba78e91b05c12814.patch)
b2sums=('1d7ee1703388d98c41524f64a99859216b060daad4502c4118adf31a95d45aa230d058630ae8735282a9b5d9f7c1ee464fb4caf9f92e3e55340370e007102f8d'
        'b9c02d4620c6d70e5fa828d1cc8aa4a42311c988becec40f4f2c65ce59a637ebf3db45cb91734b8c8c45ff73ec02dff76bcec5326ae42106fc43210a9bd29040')

prepare() {
  cd $pkgname-$pkgver-stable
  patch -p1 -R -i../06c42d151cf7b70b73dda42eba78e91b05c12814.patch
}

build() {
  # Not unbundled: enet (contains no upstreamed IPv6 support), libwebm (AUR), recast,
  #                squish (AUR), libsquish, wslay (AUR), xatlas
  local to_unbundle="bullet certs embree freetype libogg libpng libtheora libvorbis libvpx libwebp mbedtls miniupnpc opus pcre2 zlib zstd"
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
    CFLAGS="$CFLAGS" \
    CXXFLAGS="$CXXFLAGS" \
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
