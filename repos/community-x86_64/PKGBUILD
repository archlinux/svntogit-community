# vim:set ts=2 sw=2 et:
# $Id$
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
pkgname=('kodi' 'kodi-eventclients' 'kodi-tools-texturepacker' 'kodi-dev')
pkgver=17.6
_codename=Krypton
pkgrel=8
arch=('x86_64')
url="http://kodi.tv"
license=('GPL2')
makedepends=(
  'afpfs-ng' 'bluez-libs' 'cmake' 'curl' 'doxygen' 'glew'
  'gperf' 'hicolor-icon-theme' 'jasper' 'java-runtime' 'libaacs' 'libass'
  'libbluray' 'libcdio' 'libcec' 'libgl' 'libmariadbclient' 'libmicrohttpd'
  'libmodplug' 'libmpeg2' 'libnfs' 'libplist' 'libpulse' 'libssh' 'libva'
  'libvdpau' 'libxrandr' 'libxslt' 'lzo' 'mesa' 'nasm' 'nss-mdns'
  'python2-pillow' 'python2-pybluez' 'python2-simplejson' 'rtmpdump'
  'shairplay' 'smbclient' 'speex' 'swig' 'taglib' 'tinyxml' 'unzip' 'upower'
  'yajl' 'zip' 'git' 'giflib'
)
_libdvdcss_commit="2f12236bc1c92f73c21e973363f79eb300de603f"
_libdvdnav_commit="981488f7f27554b103cca10c1fbeba027396c94a"
_libdvdread_commit="17d99db97e7b8f23077b342369d3c22a6250affd"
_ffmpeg_version="3.1.11-$_codename-17.5"
source=(
  "$pkgbase-$pkgver-$_codename.tar.gz::https://github.com/xbmc/xbmc/archive/$pkgver-$_codename.tar.gz"
  "$pkgbase-libdvdcss-$_libdvdcss_commit.tar.gz::https://github.com/xbmc/libdvdcss/archive/$_libdvdcss_commit.tar.gz"
  "$pkgbase-libdvdnav-$_libdvdnav_commit.tar.gz::https://github.com/xbmc/libdvdnav/archive/$_libdvdnav_commit.tar.gz"
  "$pkgbase-libdvdread-$_libdvdread_commit.tar.gz::https://github.com/xbmc/libdvdread/archive/$_libdvdread_commit.tar.gz"
  "$pkgbase-ffmpeg-$_ffmpeg_version.tar.gz::https://github.com/xbmc/FFmpeg/archive/$_ffmpeg_version.tar.gz"
  'fix-python-lib-path.patch'
  'cheat-sse-build.patch'
  'cpuinfo'
)
noextract=(
  "$pkgbase-libdvdcss-$_libdvdcss_commit.tar.gz"
  "$pkgbase-libdvdnav-$_libdvdnav_commit.tar.gz"
  "$pkgbase-libdvdread-$_libdvdread_commit.tar.gz"
  "$pkgbase-ffmpeg-$_ffmpeg_version.tar.gz"
)
sha512sums=('1f1ba91e6129ab423f9ad47b63d7bb75775dbf18638a96413a572aaa790f4f0d738ca35486513e158a7f55d501f78f08dd9d68aabe2fbb80a729c6091b264111'
            '12ba7aa653fcb26d5336bf2a8110c924d634cec79f684bbf19dc38ea33f69fb68c22c97f4c09e5ca7c35f95f6c324a6d70ccc2c501a99122a9321cafd33b2cd9'
            '005355da5e3d34f69737f7c3fe7884e82ffdc8f654f337e97d4a4d1e486c9f346f63b4dee74de2765e7a8d94925de5d25c3c82da732d2e8d4f58fcfeb9dd2586'
            'e59ae0bfdc62698e407e3d70503c6a7c5e308545c9dae7843e25db3b5b62d9b26256be77ef4e884263add6b4abec3438c324bfd5715f6ca2ce7fa5962d43a6c2'
            'b28bb6970c6767213f34e5f4f3e48ad5219a6c668a5264ff7de0a42712cb7393f389ddd88f56785a2dc8089f8231ae5fd05adfa10dbf15ea3e0ad7bc2ccd4d73'
            '0f41604e38648969572a66d1124d6e090c3bfca4f9d8ccabcd1806254c38b178ee08df35e1bbbd1228f820729df52353321b3257122af601c3233dbc6405c6d2'
            'be8d6b77088373d0173dee6434ebd04c9382fb00190641b392a6f9f5338b35d186f6d871aaea4a01908f283a452b23de3a1113947d9070e77fde531e32458f7e'
            '539b33f30f6735caaf57fb9f19de449b8a8902362ae9e66a6fceabd530d02888533d2ab262fb187670780c997e5c1d23bd715a3c6860fd50280c1031f47865f7')

prepare() {
  [[ -d kodi-build ]] && rm -rf kodi-build
  mkdir kodi-build

  cd "xbmc-$pkgver-$_codename"
  patch -p1 -i "$srcdir/fix-python-lib-path.patch"
  # detect if building in arch chroot
  if [[ "$srcdir" =~ ^\/build.* ]]; then
    patch -p1 -i "$srcdir/cheat-sse-build.patch"
  fi
}

build() {
  cd kodi-build
  cmake -DCMAKE_INSTALL_PREFIX=/usr \
    -DCMAKE_INSTALL_LIBDIR=/usr/lib \
    -DENABLE_EVENTCLIENTS=ON \
    -DLIRC_DEVICE=/run/lirc/lircd \
    -Dlibdvdcss_URL="$srcdir/$pkgbase-libdvdcss-$_libdvdcss_commit.tar.gz" \
    -Dlibdvdnav_URL="$srcdir/$pkgbase-libdvdnav-$_libdvdnav_commit.tar.gz" \
    -Dlibdvdread_URL="$srcdir/$pkgbase-libdvdread-$_libdvdread_commit.tar.gz" \
    -DFFMPEG_URL="$srcdir/$pkgbase-ffmpeg-$_ffmpeg_version.tar.gz" \
    ../"xbmc-$pkgver-$_codename"/project/cmake
  make
  make preinstall
}

# kodi
# components: kodi, kodi-bin

package_kodi() {
  pkgdesc="A software media player and entertainment hub for digital media"
  depends=(
    'bluez-libs' 'desktop-file-utils' 'freetype2' 'fribidi'
    'hicolor-icon-theme' 'libass' 'libcdio' 'libjpeg-turbo' 'libmariadbclient'
    'libmicrohttpd' 'libpulse' 'libssh' 'libva' 'libvdpau' 'libxrandr'
    'libxslt' 'lzo' 'mesa' 'python2-pillow' 'python2-simplejson' 'smbclient'
    'speex' 'taglib' 'tinyxml' 'xorg-xdpyinfo' 'yajl'
  )
  optdepends=(
    'afpfs-ng: Apple shares support'
    'bluez: Blutooth support'
    'python2-pybluez: Bluetooth support'
    'libnfs: NFS shares support'
    'libplist: AirPlay support'
    'libcec: Pulse-Eight USB-CEC adapter support'
    'lirc: Remote controller support'
    'lsb-release: log distro information in crashlog'
    'pulseaudio: PulseAudio support'
    'shairplay: AirPlay support'
    'unrar: Archives support'
    'unzip: Archives support'
    'upower: Display battery level'
  )
  provides=('xbmc')
  conflicts=('xbmc')
  replaces=('xbmc')

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

  # Licenses
  install -dm755 "$pkgdir/usr/share/licenses/$pkgname"
  for licensef in LICENSE.GPL copying.txt; do
    mv "$pkgdir/usr/share/doc/kodi/$licensef" \
      "$pkgdir/usr/share/licenses/$pkgname"
  done

  # python2 is being used
  cd "$pkgdir"
  grep -lR '#!.*python' * | while read file; do sed -s 's/\(#!.*python\)/\12/g' -i "$file"; done
}

# kodi-eventclients
# components: kodi-eventclients-common kodi-eventclients-ps3 kodi-eventclients-wiiremote kodi-eventclients-xbmc-send

package_kodi-eventclients() {
  pkgdesc="Kodi Event Clients"
  conflicts=('kodi-eventclients')
  optdepends=('python2: most eventclients are implemented in python2')

  _components=(
    'kodi-eventclients-common'
    'kodi-eventclients-ps3'
    'kodi-eventclients-xbmc-send'
  )

  cd kodi-build
  # install eventclients
  for _cmp in ${_components[@]}; do
    DESTDIR="$pkgdir" /usr/bin/cmake \
      -DCMAKE_INSTALL_COMPONENT="$_cmp" \
      -P cmake_install.cmake
  done

  # python2 is being used
  cd "$pkgdir"
  grep -lR '#!.*python' * | while read file; do sed -s 's/\(#!.*python\)/\12/g' -i "$file"; done
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
# components: kodi-addon-dev kodi-audio-dev kodi-eventclients-dev kodi-game-dev kodi-inputstream-dev kodi-peripheral-dev kodi-pvr-dev kodi-screensaver-dev kodi-visualization-dev

package_kodi-dev() {
  pkgdesc="Kodi dev files"
  depends=('kodi')

  _components=(
    'kodi-addon-dev'
    'kodi-audio-dev'
    'kodi-eventclients-dev'
    'kodi-game-dev'
    'kodi-inputstream-dev'
    'kodi-peripheral-dev'
    'kodi-pvr-dev'
    'kodi-screensaver-dev'
    'kodi-visualization-dev'
  )

  cd kodi-build
  # install eventclients
  for _cmp in ${_components[@]}; do
    DESTDIR="$pkgdir" /usr/bin/cmake \
      -DCMAKE_INSTALL_COMPONENT="$_cmp" \
      -P cmake_install.cmake
  done

  # python2 is being used
  cd "$pkgdir"
  grep -lR '#!.*python' * | while read file; do sed -s 's/\(#!.*python\)/\12/g' -i "$file"; done
}
