# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: loqs
# Contributor: Jorge Araya Navarro <jorgejavieran@yahoo.com.mx>
# Contributor: Cristian Porras <porrascristian@gmail.com>
# Contributor: Matthew Bentley <matthew@mtbentley.us>

pkgbase=godot
pkgname=(godot)
pkgver=4.0.2
pkgrel=5
pkgdesc='Advanced cross-platform 2D and 3D game engine'
url='https://godotengine.org/'
license=(MIT)
arch=(x86_64)
makedepends=(alsa-lib pulseaudio scons yasm)
depends=(embree3 freetype2 graphite harfbuzz harfbuzz-icu libglvnd libspeechd
         libsquish libtheora libvorbis libwebp libwslay libxcursor libxi
         libxinerama libxrandr mbedtls2 miniupnpc pcre2)
optdepends=(pipewire-alsa pipewire-pulse)
source=("$pkgbase-$pkgver.tar.gz::https://github.com/godotengine/godot/archive/$pkgver-stable.tar.gz")
b2sums=('56069525ee31d6750c6c0107a58e8cb90ad0d06d5a521c127dbe5ba102577a1a8a906ac2c2eeb250156ad3ffbd5c3c3d2c3a590cfd2240ddc2b004b8e8dff208')
sha256sums=('d978282597c5e3a398ad3ade8b5a68d351178c82b197fa6a64045f4abc37e5a6')

prepare() {
  # Update the MIME info, ref FS#77810
  sed -i 's,xmlns="https://specifications.freedesktop.org/shared-mime-info-spec",xmlns="http://www.freedesktop.org/standards/shared-mime-info",g' \
    $pkgbase-$pkgver-stable/misc/dist/linux/org.godotengine.Godot.xml
}

build() {
  cd $pkgbase-$pkgver-stable
  export BUILD_NAME=arch_linux
  # Not unbundled (yet):
  #  enet (contains no upstreamed IPv6 support)
  #  AUR: libwebm, rvo2
  #  recastnavigation, xatlas
  scons -j$(nproc --all) \
    CFLAGS="$CFLAGS -fPIC -Wl,-z,relro,-z,now -w -I/usr/include/mbedtls2" \
    CXXFLAGS="$CXXFLAGS -fPIC -Wl,-z,relro,-z,now -w -I/usr/include/mbedtls2" \
    LINKFLAGS="$LDFLAGS -L/usr/lib/mbedtls2" \
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
    werror=no
}

package_godot() {
  cd $pkgbase-$pkgver-stable
  install -Dm644 misc/dist/linux/org.godotengine.Godot.desktop \
    "$pkgdir/usr/share/applications/godot.desktop"
  install -Dm644 icon.svg "$pkgdir/usr/share/pixmaps/godot.svg"
  install -Dm644 LICENSE.txt "$pkgdir/usr/share/licenses/godot/LICENSE"
  install -Dm644 misc/dist/linux/godot.6 "$pkgdir/usr/share/man/man6/godot.6"
  install -Dm644 misc/dist/linux/org.godotengine.Godot.xml \
    "$pkgdir/usr/share/mime/packages/org.godotengine.Godot.xml"
  install -Dm755 bin/godot.linuxbsd.editor.$CARCH "$pkgdir/usr/bin/godot"
}
