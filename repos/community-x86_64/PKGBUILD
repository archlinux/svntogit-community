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
pkgver=17.3
_codename=Krypton
pkgrel=3
arch=('i686' 'x86_64')
url="http://kodi.tv"
license=('GPL2')
makedepends=(
  'afpfs-ng' 'bluez-libs' 'boost' 'cmake' 'curl' 'cwiid' 'doxygen' 'glew'
  'gperf' 'hicolor-icon-theme' 'jasper' 'java-runtime' 'libaacs' 'libass'
  'libbluray' 'libcdio' 'libcec' 'libgl' 'libmariadbclient' 'libmicrohttpd'
  'libmodplug' 'libmpeg2' 'libnfs' 'libplist' 'libpulse' 'libssh' 'libva'
  'libvdpau' 'libxrandr' 'libxslt' 'lzo' 'nasm' 'nss-mdns' 'python2-pillow'
  'python2-pybluez' 'python2-simplejson' 'rtmpdump'
  'shairplay' 'smbclient' 'swig' 'taglib' 'tinyxml' 'unzip' 'upower' 'yajl' 'zip'
  'mesa' 'libcrossguid'
  'hardening-wrapper'
)
source=(
  "$pkgname-$pkgver-$_codename.tar.gz::https://github.com/xbmc/xbmc/archive/$pkgver-$_codename.tar.gz"
  'fix-python-lib-path.patch'
)
sha512sums=('832071c3e9f332281a767f29168f6d6d003a86b42df849e81d907c2280f81f959ae42a850eddc889ae2280bba6106de3355e701ff2d71c88ee14cb20c84e7987'
            '0f41604e38648969572a66d1124d6e090c3bfca4f9d8ccabcd1806254c38b178ee08df35e1bbbd1228f820729df52353321b3257122af601c3233dbc6405c6d2')

prepare() {
  [[ -d kodi-build ]] && rm -rf kodi-build
  mkdir kodi-build

  cd "xbmc-$pkgver-$_codename"
  patch -p1 -i "$srcdir/fix-python-lib-path.patch"
}

build() {
  cd kodi-build
  cmake -DCMAKE_INSTALL_PREFIX=/usr \
    -DCMAKE_INSTALL_LIBDIR=/usr/lib \
    -DENABLE_EVENTCLIENTS=ON \
    -DLIRC_DEVICE=/run/lirc/lircd \
    ../"xbmc-$pkgver-$_codename"/project/cmake
  make
  make preinstall
}

# kodi
# components: kodi, kodi-bin

package_kodi() {
  pkgdesc="A software media player and entertainment hub for digital media"
  depends=(
    'python2-pillow' 'python2-simplejson' 'xorg-xdpyinfo' 'bluez-libs'
    'fribidi' 'freetype2' 'glew' 'hicolor-icon-theme' 'libcdio' 'libjpeg-turbo'
    'libmariadbclient' 'libmicrohttpd' 'libpulse' 'libssh' 'libva' 'libvdpau'
    'libxrandr' 'libxslt' 'lzo' 'smbclient' 'taglib' 'tinyxml' 'yajl' 'mesa'
    'desktop-file-utils'
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

  depends=('cwiid')

  _components=(
    'kodi-eventclients-common'
    'kodi-eventclients-ps3'
    'kodi-eventclients-wiiremote'
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
