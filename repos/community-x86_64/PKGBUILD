# vim:set ts=2 sw=2 et:
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Maintainer: BlackIkeEagle < ike DOT devolder AT gmail DOT com >
# Contributor: graysky <graysky AT archlinux DOT us>
# Contributor: DonVla <donvla@users.sourceforge.net>
# Contributor: Ulf Winkelvos <ulf [at] winkelvos [dot] de>
# Contributor: Ralf Barth <archlinux dot org at haggy dot org>
# Contributor: B & monty - Thanks for your hints :)
# Contributor: marzoul
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Brad Fanella <bradfanella@archlinux.us>
# Contributor: [vEX] <niechift.dot.vex.at.gmail.dot.com>
# Contributor: Zeqadious <zeqadious.at.gmail.dot.com>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Maxime Gauduin <alucryd@gmail.com>
#
# Original credits go to Edgar Hucek <gimli at dark-green dot com>
# for his xbmc-vdpau-vdr PKGBUILD at https://archvdr.svn.sourceforge.net/svnroot/archvdr/trunk/archvdr/xbmc-vdpau-vdr/PKGBUILD

pkgbase=kodi
pkgname=(
  'kodi-common' 'kodi-x11' 'kodi-wayland' 'kodi-gbm'
  'kodi-eventclients' 'kodi-tools-texturepacker' 'kodi-dev'
)
pkgver=19.0
pkgrel=6
arch=('x86_64')
url="https://kodi.tv"
license=('GPL2')
makedepends=(
  'afpfs-ng' 'bluez-libs' 'cmake' 'curl' 'dav1d' 'doxygen' 'git' 'glew'
  'gperf' 'hicolor-icon-theme' 'java-runtime' 'libaacs' 'libass'
  'libbluray' 'libcdio' 'libcec' 'libgl' 'mariadb-libs' 'libmicrohttpd'
  'libmodplug' 'libmpeg2' 'libnfs' 'libplist' 'libpulse' 'libva'
  'libva-vdpau-driver' 'libxrandr' 'libxslt' 'lirc' 'lzo' 'mesa' 'nasm'
  'python-pycryptodomex' 'python-pillow' 'python-pybluez'
  'python-simplejson' 'shairplay' 'smbclient' 'taglib' 'tinyxml' 'swig'
  'upower' 'giflib' 'rapidjson' 'ghostscript' 'meson' 'gtest' 'graphviz'
  # wayland
  'wayland-protocols' 'waylandpp' 'libxkbcommon'
  # gbm
  'libinput'
)

_codename=Matrix

_sse_workaround=1

_libdvdcss_version="1.4.2-Leia-Beta-5"
_libdvdnav_version="6.0.0-Leia-Alpha-3"
_libdvdread_version="6.0.0-Leia-Alpha-3"
_ffmpeg_version="4.3.1-$_codename-Beta1"
_fmt_version="6.1.2"
_spdlog_version="1.5.0"
_crossguid_version="8f399e8bd4"
_fstrcmp_version="0.7.D001"
_flatbuffers_version="1.11.0"

source=(
  "$pkgbase-$pkgver-$_codename.tar.gz::https://github.com/xbmc/xbmc/archive/$pkgver-$_codename.tar.gz"
  "$pkgbase-libdvdcss-$_libdvdcss_version.tar.gz::https://github.com/xbmc/libdvdcss/archive/$_libdvdcss_version.tar.gz"
  "$pkgbase-libdvdnav-$_libdvdnav_version.tar.gz::https://github.com/xbmc/libdvdnav/archive/$_libdvdnav_version.tar.gz"
  "$pkgbase-libdvdread-$_libdvdread_version.tar.gz::https://github.com/xbmc/libdvdread/archive/$_libdvdread_version.tar.gz"
  "$pkgbase-ffmpeg-$_ffmpeg_version.tar.gz::https://github.com/xbmc/FFmpeg/archive/$_ffmpeg_version.tar.gz"
  "$pkgbase-fmt-$_fmt_version.tar.gz::http://mirrors.kodi.tv/build-deps/sources/fmt-$_fmt_version.tar.gz"
  "$pkgbase-spdlog-$_spdlog_version.tar.gz::http://mirrors.kodi.tv/build-deps/sources/spdlog-$_spdlog_version.tar.gz"
  "$pkgbase-crossguid-$_crossguid_version.tar.gz::http://mirrors.kodi.tv/build-deps/sources/crossguid-$_crossguid_version.tar.gz"
  "$pkgbase-fstrcmp-$_fstrcmp_version.tar.gz::http://mirrors.kodi.tv/build-deps/sources/fstrcmp-$_fstrcmp_version.tar.gz"
  "$pkgbase-flatbuffers-$_flatbuffers_version.tar.gz::http://mirrors.kodi.tv/build-deps/sources/flatbuffers-$_flatbuffers_version.tar.gz"
  'cheat-sse-build.patch'
  '0001-allow-separate-windowing-binaries-being-launched-fro.patch'
)
noextract=(
  "$pkgbase-libdvdcss-$_libdvdcss_version.tar.gz"
  "$pkgbase-libdvdnav-$_libdvdnav_version.tar.gz"
  "$pkgbase-libdvdread-$_libdvdread_version.tar.gz"
  "$pkgbase-ffmpeg-$_ffmpeg_version.tar.gz"
  "$pkgbase-fmt-$_fmt_version.tar.gz"
  "$pkgbase-spdlog-$_spdlog_version.tar.gz"
  "$pkgbase-crossguid-$_crossguid_version.tar.gz"
  "$pkgbase-fstrcmp-$_fstrcmp_version.tar.gz"
  "$pkgbase-flatbuffers-$_flatbuffers_version.tar.gz"
)
sha512sums=('d6c9fe7414b64d33d919d6c3de1ddb4800e36b786a460d2d2f5c1e5346cd4819487e54f212c37778103d44dd051f7df6c74e0a98a0b21d1e4dc9bedaa8570422'
            '5185dbdbeb1bd13ea9d8723f1f4ab599d6f3102f5ba1096cd085aa1cda252c045f327c719227bba8e1b742352ade5e335106c8d0c1637a5a6b93ce661620dd7e'
            '11c93eaacd156f8fd7dec7c43d366438b201f31ad55b2870463a9e286912b6ada08882319a021fb7992190f87b909a49f2b83e0321cc17aedc29f7fe5898fa72'
            'b3419ba0a1a2dd70f1bb6236afdfe1c6e88c9ad4264198b289e3bba9375e077cecf7f89848c7b09debaa445327f3507101f3d157e692f7a7163b2bb52643e1e7'
            'ce43390e816dabeed4ca231f5f7adade6c721c38e17996a57810fb6025ea49b812133c2a6e29aac7c674d4e4af3a21dbd7e605d85fb966935a01bda983b884ac'
            '8770bf4bd2bb6d938e75e0cf1e665c41930dbd9d2a6825274a5a43cd1d85b9c9ca621bb040ed099429f0e16bddbc3399361c453eb1bf3fc01376e6ad9dd875b7'
            '78991c943dd95af563c4b29545b9b5d635caf1af5031262dde734ecf70c0b4ae866d954ee77b050f9f0cc089a3bc57ee9583895e51cb00dd1cc6c10ff905ca34'
            '2682d63609d3dcdfcd8136be632e45df26ad88ce93b9c49745cf728bbd2e6254a7b05c8b059ab581d532372e504206a525a52564b64d076dfdae9c965a09fd16'
            'aaeb0227afd5ada5955cbe6a565254ff88d2028d677d199c00e03b7cb5de1f2c69b18e6e8b032e452350a8eda7081807b01765adbeb8476eaf803d9de6e5509c'
            'e4a6fbc5813041194ac66d2d019aea711dad72239f52731f292675cd21248cba139768aa80f044c3a11cae2d308ae95b4b45de914d207b5b1d3d5d18620c8882'
            '91409cc66959a30f2d0dbf8d28e47dd2acbac560efb8961550c5928ae8546a32d1f156f8e55f073f953b114230117ec96c224212d28c1c1d752540c836c9ae1a'
            '372eb5ef438458a3fd2d38c20ad9385e208d670bdc8e5ffb62c5bde2e3e93a3548704118aced33e6a956e12ae70a42316afafa482cf16e171dd0f07330de3509')

prepare() {
  [[ -d kodi-build ]] && rm -rf kodi-build
  mkdir "$srcdir/kodi-build"

  cd "xbmc-$pkgver-$_codename"

  [[ "$_sse_workaround" -eq 1 ]] && patch -p1 -i "$srcdir/cheat-sse-build.patch"

  patch -p1 -i "$srcdir/0001-allow-separate-windowing-binaries-being-launched-fro.patch"
}

build() {
  cd "$srcdir/kodi-build"

  _cmake_common_args=(
    -DCMAKE_INSTALL_PREFIX=/usr
    -DCMAKE_INSTALL_LIBDIR=/usr/lib
    -DUSE_LTO=ON
    -DENABLE_LDGOLD=OFF
    -DENABLE_EVENTCLIENTS=ON
    -DENABLE_INTERNAL_FFMPEG=ON
    -DENABLE_INTERNAL_FMT=ON
    -DENABLE_INTERNAL_SPDLOG=ON
    -DENABLE_INTERNAL_CROSSGUID=ON
    -DENABLE_INTERNAL_FSTRCMP=ON
    -DENABLE_INTERNAL_FLATBUFFERS=ON
    -DENABLE_MYSQLCLIENT=ON
    -Dlibdvdcss_URL="$srcdir/$pkgbase-libdvdcss-$_libdvdcss_version.tar.gz"
    -Dlibdvdnav_URL="$srcdir/$pkgbase-libdvdnav-$_libdvdnav_version.tar.gz"
    -Dlibdvdread_URL="$srcdir/$pkgbase-libdvdread-$_libdvdread_version.tar.gz"
    -DFFMPEG_URL="$srcdir/$pkgbase-ffmpeg-$_ffmpeg_version.tar.gz"
    -DFMT_URL="$srcdir/$pkgbase-fmt-$_fmt_version.tar.gz"
    -DSPDLOG_URL="$srcdir/$pkgbase-spdlog-$_spdlog_version.tar.gz"
    -DCROSSGUID_URL="$srcdir/$pkgbase-crossguid-$_crossguid_version.tar.gz"
    -DFSTRCMP_URL="$srcdir/$pkgbase-fstrcmp-$_fstrcmp_version.tar.gz"
    -DFLATBUFFERS_URL="$srcdir/$pkgbase-flatbuffers-$_flatbuffers_version.tar.gz"
  )

  echo "building kodi-x11"
  cmake \
    ${_cmake_common_args[@]} \
    -DCORE_PLATFORM_NAME=x11 \
    -DAPP_RENDER_SYSTEM=gl \
    ../"xbmc-$pkgver-$_codename"
  make

  echo "building kodi-wayland"
  cmake \
    ${_cmake_common_args[@]} \
    -DCORE_PLATFORM_NAME=wayland \
    -DAPP_RENDER_SYSTEM=gl \
    ../"xbmc-$pkgver-$_codename"
  make

  echo "building kodi-gbm"
  cmake \
    ${_cmake_common_args[@]} \
    -DCORE_PLATFORM_NAME=gbm \
    -DAPP_RENDER_SYSTEM=gl \
    ../"xbmc-$pkgver-$_codename"
  make
}

# kodi
# components: kodi

package_kodi-common() {
  pkgdesc="A software media player and entertainment hub for digital media"
  depends=(
    'bluez-libs' 'curl' 'desktop-file-utils' 'hicolor-icon-theme' 'lcms2'
    'libass' 'libbluray' 'libcdio' 'libcec' 'libmicrohttpd' 'libnfs' 'libplist'
    'libpulse' 'libva' 'libxslt' 'lirc' 'mariadb-libs' 'mesa' 'python'
    'python-pillow' 'python-pycryptodomex' 'python-simplejson' 'shairplay'
    'smbclient' 'taglib' 'tinyxml'
  )
  optdepends=(
    'afpfs-ng: Apple shares support'
    'bluez: Blutooth support'
    'python-pybluez: Bluetooth support'
    'pulseaudio: PulseAudio support'
    'upower: Display battery level'
  )

  _components=(
    'kodi'
    'kodi-bin'
  )

  cd kodi-build
  # install eventclients
  for _cmp in ${_components[@]}; do
  DESTDIR="$pkgdir" /usr/bin/cmake \
    -DCMAKE_INSTALL_COMPONENT="$_cmp" \
     -P cmake_install.cmake
  done

  # remove windowing specific binaries
  rm -f "$pkgdir/usr/lib/kodi/"{kodi-x11,kodi-xrandr,kodi-wayland,kodi-gbm}
}

# kodi-x11
# components: kodi-bin

package_kodi-x11() {
  pkgdesc="x11 kodi binary"
  provides=('kodi')
  replaces=('kodi')
  depends=(
    'kodi-common' 'libva-vdpau-driver' 'libxrandr'
  )

  cd kodi-build
  install -Dm755 kodi-x11 "$pkgdir/usr/lib/kodi/kodi-x11"
  install -Dm755 kodi-xrandr "$pkgdir/usr/lib/kodi/kodi-xrandr"
}

# kodi-wayland
# components: kodi-bin

package_kodi-wayland() {
  pkgdesc="wayland kodi binary"
  provides=('kodi')
  replaces=('kodi')
  depends=(
    'kodi-common' 'libxkbcommon' 'waylandpp'
  )

  cd kodi-build
  install -Dm755 kodi-wayland "$pkgdir/usr/lib/kodi/kodi-wayland"
}

# kodi-gbm
# components: kodi-bin

package_kodi-gbm() {
  pkgdesc="gbm kodi binary"
  provides=('kodi')
  replaces=('kodi')
  depends=(
    'kodi-common' 'libxkbcommon'
  )

  cd kodi-build
  install -Dm755 kodi-gbm "$pkgdir/usr/lib/kodi/kodi-gbm"
}

# kodi-eventclients
# components: kodi-eventclients-common kodi-eventclients-ps3 kodi-eventclients-kodi-send

package_kodi-eventclients() {
  pkgdesc="Kodi Event Clients"
  optdepends=(
    'kodi: local machine eventclient use'
    'python: most eventclients are implemented in python'
  )

  _components=(
    'kodi-eventclients-common'
    'kodi-eventclients-ps3'
    'kodi-eventclients-kodi-send'
  )

  cd kodi-build
  # install eventclients
  for _cmp in ${_components[@]}; do
    DESTDIR="$pkgdir" /usr/bin/cmake \
      -DCMAKE_INSTALL_COMPONENT="$_cmp" \
      -P cmake_install.cmake
  done
}

# kodi-tools-texturepacker
# components: kodi-tools-texturepacker

package_kodi-tools-texturepacker() {
  pkgdesc="Kodi Texturepacker tool"
  depends=('libpng' 'giflib' 'libjpeg-turbo' 'lzo')

  _components=(
    'kodi-tools-texturepacker'
  )

  cd kodi-build
  # install eventclients
  for _cmp in ${_components[@]}; do
    DESTDIR="$pkgdir" /usr/bin/cmake \
      -DCMAKE_INSTALL_COMPONENT="$_cmp" \
      -P cmake_install.cmake
  done
}

# kodi-dev
# components: kodi-addon-dev kodi-eventclients-dev

package_kodi-dev() {
  pkgdesc="Kodi dev files"
  depends=('kodi-common')

  _components=(
    'kodi-addon-dev'
    'kodi-eventclients-dev'
  )

  cd kodi-build
  # install eventclients
  for _cmp in ${_components[@]}; do
    DESTDIR="$pkgdir" /usr/bin/cmake \
      -DCMAKE_INSTALL_COMPONENT="$_cmp" \
      -P cmake_install.cmake
  done
}
