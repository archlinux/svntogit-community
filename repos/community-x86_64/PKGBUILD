# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: loqs
# Contributor: Jorge Araya Navarro <jorgejavieran@yahoo.com.mx>
# Contributor: Cristian Porras <porrascristian@gmail.com>
# Contributor: Matthew Bentley <matthew@mtbentley.us>

pkgname=godot
pkgver=4.0
pkgrel=1
pkgdesc='Advanced cross-platform 2D and 3D game engine'
url='https://godotengine.org'
license=(MIT)
arch=(x86_64)
makedepends=(gcc scons yasm alsa-lib pulseaudio)
depends=(embree freetype2 graphite harfbuzz harfbuzz-icu libglvnd libspeechd
         libsquish libtheora libvorbis libwebp libwslay libxcursor libxi
         libxinerama libxrandr mbedtls miniupnpc pcre2)
optdepends=(pipewire-alsa pipewire-pulse)
source=("$pkgname-$pkgver.tar.gz::https://github.com/godotengine/godot/archive/$pkgver-stable.tar.gz"
        libsquish.pc)
b2sums=('eea911f510d1b5fb55e7b8ed2e088fb549c550b6e951b850a4ca677ca1f52358a96ad8416f592042074338fd94becc4d85e37e7428c1094b1b9a4fd6580e32b8'
        '39f9db4957e2a1e5875c3bfc438acabad8b76cd19e5b9a79f3101972165650577e7fd2a7c03df2ca629d4f332fccb6c84025e335fd8d0cf794f30d627e63937d')

build() {
  # Not unbundled (yet):
  #  enet (contains no upstreamed IPv6 support)
  #  AUR: libwebm, rvo2
  #  recast, xatlas
  cd $pkgname-$pkgver-stable
  export BUILD_NAME=arch_linux
  # for scons to find squish through pkg-config
  export PKG_CONFIG_PATH="$srcdir:$(pkg-config --variable pc_path pkg-config):$PKG_CONFIG_PATH"
  scons -j16 \
    arch=$CARCH \
    builtin_embree=no \
    builtin_enet=yes \
    builtin_freetype=no \
    builtin_msdfgen=yes \
    builtin_glslang=yes \
    builtin_graphite=no \
    builtin_harfbuzz=no \
    builtin_icu4c=yes \
    builtin_libogg=no \
    builtin_libpng=no \
    builtin_libtheora=no \
    builtin_libvorbis=no \
    builtin_libwebp=no \
    builtin_wslay=yes \
    builtin_mbedtls=no \
    builtin_miniupnpc=no \
    builtin_pcre2=no \
    builtin_pcre2_with_jit=no \
    builtin_recastnavigation=yes \
    builtin_rvo2=yes \
    builtin_squish=no \
    builtin_xatlas=yes \
    builtin_zlib=no \
    builtin_zstd=no \
    colored=yes \
    platform=linuxbsd \
    production=yes \
    pulseaudio=yes \
    system_certs_path=/etc/ssl/certs/ca-certificates.crt \
    target=editor \
    use_llvm=no \
    werror=no \
    CFLAGS="$CFLAGS -fPIC -Wl,-z,relro,-z,now -w" \
    CXXFLAGS="$CXXFLAGS -fPIC -Wl,-z,relro,-z,now -w" \
    LINKFLAGS="$LDFLAGS" \
    $system_libs
}

package() {
  cd $pkgname-$pkgver-stable
  install -Dm644 misc/dist/linux/org.godotengine.Godot.desktop \
    "$pkgdir/usr/share/applications/godot.desktop"
  install -Dm644 icon.svg "$pkgdir/usr/share/pixmaps/godot.svg"
  install -Dm755 bin/godot.linuxbsd.editor.$CARCH "$pkgdir/usr/bin/godot"
  install -Dm644 LICENSE.txt "$pkgdir/usr/share/licenses/godot/LICENSE"
  install -Dm644 misc/dist/linux/godot.6 "$pkgdir/usr/share/man/man6/godot.6"
  install -Dm644 misc/dist/linux/org.godotengine.Godot.xml \
    "$pkgdir/usr/share/mime/packages/org.godotengine.Godot.xml"
}
