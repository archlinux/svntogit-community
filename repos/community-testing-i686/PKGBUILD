# vim:set ts=2 sw=2 et:
# $Id$
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Maintainer: BlackIkeEagle < ike DOT devolder AT gmail DOT com >
# Contributor: Brad Fanella <bradfanella@archlinux.us>
# Contributor: [vEX] <niechift.dot.vex.at.gmail.dot.com>
# Contributor: Zeqadious <zeqadious.at.gmail.dot.com>
# Contributor: BlackIkeEagle < ike DOT devolder AT gmail DOT com >
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Maxime Gauduin <alucryd@gmail.com>

_prefix=/usr

pkgbase=kodi
pkgname=('kodi' 'kodi-texturepacker')
pkgver=14.0
_codename=Helix
pkgrel=0.5
arch=('i686' 'x86_64')
url="http://kodi.tv"
license=('GPL2')
makedepends=(
'bluez-libs' 'curl' 'glew' 'hicolor-icon-theme' 'libaacs'
'libass' 'libbluray' 'libcdio' 'libmariadbclient' 'libmicrohttpd'
'libpulse' 'libssh' 'libva' 'libvdpau' 'libxrandr'
'libxslt' 'lzo' 'libgl' 'python2-pillow' 'python2-pybluez'
'python2-simplejson' 'rtmpdump' 'smbclient' 'taglib' 'tinyxml'
'yajl'
'afpfs-ng' 'boost' 'cmake' 'doxygen' 'git' 'gperf' 'jasper'
'java-runtime' 'libcec' 'libnfs' 'libplist' 'nasm' 'shairplay'
'swig' 'unzip' 'upower' 'zip'
'libmpeg2' 'libmodplug'
'sdl2' 'sdl_image'
)
# encoders
# flac
# lame
# libmodplug
# libvorbis
source=(
  "$pkgname-$pkgver-$_codename.tar.gz::https://github.com/xbmc/xbmc/archive/$pkgver-$_codename.tar.gz"
)
sha256sums=(
  '11746d95cc59361f36ce6ea9d0d36bbd9ec3376e991f5ec1720f8ff740b91192'
)

prepare() {
  cd "$srcdir/xbmc-$pkgver-$_codename"


  find -type f -name *.py -exec sed 's|^#!.*python$|#!/usr/bin/python2|' -i "{}" +
  sed 's|^#!.*python$|#!/usr/bin/python2|' -i tools/depends/native/rpl-native/rpl
	sed 's/python/python2/' -i tools/Linux/kodi.sh.in
}

build() {
  cd "$srcdir/xbmc-$pkgver-$_codename"

	# Bootstrapping
  ./bootstrap

  # Configuring XBMC
  export PYTHON_VERSION=2  # external python v2
  ./configure --prefix=$_prefix --exec-prefix=$_prefix \
    --disable-debug \
    --enable-optimizations \
    --enable-gl \
    --enable-vaapi \
    --enable-vdpau \
    --enable-joystick \
    --enable-xrandr \
    --enable-rsxs \
    --enable-projectm \
    --enable-x11 \
    --enable-pulse \
    --enable-rtmp \
    --enable-samba \
    --enable-nfs \
    --enable-afpclient \
    --enable-airplay \
    --enable-airtunes \
    --enable-ffmpeg-libvorbis \
    --enable-dvdcss \
    --disable-hal \
    --enable-avahi \
    --enable-webserver \
    --enable-optical-drive \
    --enable-libbluray \
    --enable-texturepacker \
    --enable-udev \
    --enable-libusb \
    --enable-libcec \
		--enable-external-libraries \
    --with-lirc-device=/run/lirc/lircd

  # Now (finally) build
  make
}

package_kodi() {
  pkgdesc="A software media player and entertainment hub for digital media"

  # depends expected for kodi plugins:
  # 'python2-pillow' 'python2-pybluez' 'python2-simplejson'
  # depends expeced in FEH.py
  # 'mesa-demos' 'xorg-xdpyinfo'
  depends=(
    'python2-pillow' 'python2-pybluez' 'python2-simplejson'
    'mesa-demos' 'xorg-xdpyinfo'
    'bluez-libs' 'fribidi' 'glew' 'hicolor-icon-theme' 'libcdio'
    'libjpeg-turbo' 'libmariadbclient' 'libmicrohttpd' 'libpulse' 'libssh'
    'libva' 'libxrandr' 'libxslt' 'lzo' 'sdl2' 'smbclient' 'taglib' 'tinyxml'
    'yajl'
  )
  optdepends=(
    'afpfs-ng: Apple shares support'
    'bluez: Blutooth support'
    'libnfs: NFS shares support'
    'libplist: AirPlay support'
    'libcec: Pulse-Eight USB-CEC adapter support'
    'lirc: Remote controller support'
    'pulseaudio: PulseAudio support'
    'shairplay: AirPlay support'
    'udisks: Automount external drives'
    'unrar: Archives support'
    'unzip: Archives support'
    'upower: Display battery level'
  )
  install="kodi.install"
  provides=('xbmc')
  conflicts=('xbmc')
  replaces=('xbmc')

  cd "$srcdir/xbmc-$pkgver-$_codename"
  # Running make install
  make DESTDIR="$pkgdir" install

  # Licenses
	install -dm755 ${pkgdir}${_prefix}/share/licenses/${pkgname}
  for licensef in LICENSE.GPL copying.txt; do
		mv ${pkgdir}${_prefix}/share/doc/kodi/${licensef} \
			${pkgdir}${_prefix}/share/licenses/${pkgname}
  done
}

package_kodi-texturepacker() {
  pkgdesc="A tool to compile all images used in a skin into a single file."

  depends=(
    'lzo'
    'sdl_image'
  )

  cd "$srcdir/xbmc-$pkgver-$_codename"

	install -Dm755 $srcdir/xbmc-$pkgver-$_codename/tools/TexturePacker/TexturePacker \
		${pkgdir}${_prefix}/lib/kodi/TexturePacker

  install -dm755 "${pkgdir}${_prefix}/bin"
  ln -sf "${_prefix}/lib/kodi/TexturePacker" "${pkgdir}${_prefix}/bin/kodi-TexturePacker"
}
