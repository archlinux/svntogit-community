# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: David Runge <dvzrv@archlinux.org>
# Contributor: Lauri Niskanen <ape@ape3000.com>
# Contributor: Sebastian.Salich@gmx.de
# Contributor: Doc Angelo

pkgname=mumble
pkgver=1.3.2
pkgrel=1
arch=('x86_64')
pkgdesc="A voice chat application similar to TeamSpeak"
license=('BSD')
depends=('gcc-libs' 'glibc' 'hicolor-icon-theme' 'libspeechd' 'libx11' 'libxi'
'lsb-release' 'openssl' 'opus' 'qt5-base' 'qt5-svg' 'speex' 'xdg-utils')
makedepends=('alsa-lib' 'avahi' 'boost' 'jack' 'libpulse' 'libsndfile' 'mesa'
'protobuf' 'python' 'qt5-tools')
optdepends=('speech-dispatcher: Text-to-speech support'
            'espeak-ng: Text-to-speech support')
url="https://www.mumble.info/"
source=("https://github.com/mumble-voip/mumble/releases/download/${pkgver}/mumble-${pkgver}.tar.gz"{,.sig})
sha512sums=('22e23a682bc9c11420c6ae1d8ff01a80906ebbfb4f073ee25c6d2923d345d12031ddfeca3dabaaf5cf183b82b22eb3c788c88fa0f5313bc399e15795a945b874'
            'SKIP')
validpgpkeys=('76B50270322F0E3D78DCE8298AA328A315175AE3') # Mumble Automatic Build Infrastructure 2020 <mumble-auto-build-2020@mumble.info>

build() {
  cd "$pkgname-$pkgver"
  qmake-qt5 main.pro \
    CONFIG+="no-bundled-opus no-bundled-speex no-g15 no-xevie no-server \
    no-embed-qt-translations no-update packaged" \
    DEFINES+="PLUGIN_PATH=/usr/lib/mumble" \
    INCLUDEPATH+="/usr/include/speech-dispatcher"
  make release
}

package() {
  depends+=('libasound.so' 'libdns_sd.so' 'libjack.so' 'libprotobuf.so'
  'libpulse.so' 'libsndfile.so')
  cd "$pkgname-$pkgver"
  # mumble has no install target: https://github.com/mumble-voip/mumble/issues/1029
  # binaries and scripts
  install -vDm 755 release/mumble -t "$pkgdir/usr/bin"
  install -vDm 755 scripts/mumble-overlay -t "$pkgdir/usr/bin/"
  # (vendored) libs
  install -vdm 755 "$pkgdir/usr/lib/mumble/"
  local _lib
  for _lib in release/*.so*; do
    if [ -L "$_lib" ]; then
      cp -vP "$_lib" "$pkgdir/usr/lib/mumble/"
    else
      install -vDm 755 "$_lib" -t "$pkgdir/usr/lib/mumble/"
    fi
  done
  install -vDm 755 release/plugins/*.so -t "$pkgdir/usr/lib/mumble/"
  # XDG desktop integration
  install -vDm 644 scripts/mumble.desktop -t "$pkgdir/usr/share/applications"
  # man page
  install -vDm 644 "man/${pkgname}"*.1 -t "$pkgdir/usr/share/man/man1/"
  # XDG desktop icons
  install -vDm 644 icons/mumble.svg -t "$pkgdir/usr/share/icons/hicolor/scalable/apps/"
  # license
  install -vDm 644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname"
}
# vim: sw=2:ts=2 et:
