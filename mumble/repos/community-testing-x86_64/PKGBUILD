# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: David Runge <dvzrv@archlinux.org>
# Contributor: Lauri Niskanen <ape@ape3000.com>
# Contributor: Sebastian.Salich@gmx.de
# Contributor: Doc Angelo

pkgname=mumble
pkgver=1.3.0
pkgrel=9
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
source=("https://github.com/mumble-voip/mumble/releases/download/${pkgver}/mumble-${pkgver}.tar.gz"{,.sig}
        "${pkgname}-1.3.0-jack.patch::https://github.com/mumble-voip/mumble/pull/3990.patch")
sha512sums=('2a629fc97f3c7c587c9a3b40fc96cf15d668acada37282ec1c4a5b169ad37717d60af94d12c7bce45f2816c265f76a99ebad40a006adcf8ca38a117e7c0a4122'
            'SKIP'
            '11e4e1b65b8d1fb0aa07b0eff131026a6f8d6063ed57b67d9ea23152ff55e9fdb5f65691089fa8b0498d7609f6bad7e1367eb5c8b9adfd1db1d48c908618d217')
validpgpkeys=('56D0B23AE00B1EE9A8BAAC0F5B8CF87BB893449B') # Mumble Automatic Build Infrastructure 2019 <mumble-auto-build-2019@mumble.info>

prepare() {
  cd "$pkgname-$pkgver"
  # changing the default to *not* unconditionally and automatically start a
  # JACK server, when mumble is started
  # https://bugs.archlinux.org/task/62755
  # https://github.com/mumble-voip/mumble/issues/3989
  patch -Np1 -i "../${pkgname}-1.3.0-jack.patch"
}

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
