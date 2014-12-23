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

pkgname=kodi
pkgver=14.0
_codename=Helix
pkgrel=0.2
pkgdesc="A software media player and entertainment hub for digital media"
provides=('xbmc')
replaces=('xbmc')
arch=('i686' 'x86_64')
url="http://kodi.tv"
license=('GPL2')
depends=(
'bluez-libs' 'curl' 'flac' 'glew' 'hicolor-icon-theme' 'lame' 'libaacs'
'libass' 'libbluray' 'libcdio' 'libmariadbclient' 'libmicrohttpd' 'libmodplug'
'libmpeg2' 'libpulse' 'libssh' 'libva' 'libvdpau' 'libvorbis' 'libxrandr'
'libxslt' 'lzo' 'mesa' 'mesa-demos' 'python2-pillow' 'python2-pybluez'
'python2-simplejson' 'rtmpdump' 'sdl_image' 'smbclient' 'taglib' 'tinyxml'
'xorg-xdpyinfo' 'yajl'
)
makedepends=(
'afpfs-ng' 'boost' 'cmake' 'doxygen' 'git' 'gperf' 'jasper'
'java-runtime' 'libcec' 'libnfs' 'libplist' 'nasm' 'shairplay'
'swig' 'unzip' 'upower' 'zip'
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
install="${pkgname}.install"
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

package() {
  cd "$srcdir/xbmc-$pkgver-$_codename"
  # Running make install
  make DESTDIR="$pkgdir" install

  # Tools
	install -Dm755 $srcdir/xbmc-$pkgver-$_codename/tools/TexturePacker/TexturePacker \
		${pkgdir}${_prefix}/lib/kodi/

  # Licenses
	install -dm755 ${pkgdir}${_prefix}/share/licenses/${pkgname}
  for licensef in LICENSE.GPL copying.txt; do
		mv ${pkgdir}${_prefix}/share/doc/kodi/${licensef} \
			${pkgdir}${_prefix}/share/licenses/${pkgname}
  done
}
