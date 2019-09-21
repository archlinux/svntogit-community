# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: Lauri Niskanen <ape@ape3000.com>
# Contributor: Sebastian.Salich@gmx.de
# Contributor: Doc Angelo

pkgname=mumble
pkgver=1.3.0
pkgrel=2
arch=('x86_64')
pkgdesc="A voice chat application similar to TeamSpeak"
license=('BSD')
depends=(qt5-base qt5-svg speex lsb-release libxi avahi libsndfile protobuf libpulse opus
         xdg-utils libspeechd libpng freetype2 fontconfig libxrender)
makedepends=(boost mesa jack python qt5-tools)
optdepends=('jack: JACK audio output'
            'speech-dispatcher: Text-to-speech support'
            'espeak-ng: Text-to-speech support')
url="https://www.mumble.info/"
source=(https://github.com/mumble-voip/mumble/releases/download/${pkgver}/mumble-${pkgver}.tar.gz{,.sig})
sha512sums=('2a629fc97f3c7c587c9a3b40fc96cf15d668acada37282ec1c4a5b169ad37717d60af94d12c7bce45f2816c265f76a99ebad40a006adcf8ca38a117e7c0a4122'
            'SKIP')
validpgpkeys=('56D0B23AE00B1EE9A8BAAC0F5B8CF87BB893449B') # Mumble Automatic Build Infrastructure 2019 <mumble-auto-build-2019@mumble.info>

build() {
  cd "$srcdir"/$pkgname-$pkgver

  qmake-qt5 main.pro \
    CONFIG+="bundled-celt no-bundled-opus no-bundled-speex no-g15 no-xevie no-server \
    no-embed-qt-translations no-update packaged" \
    DEFINES+="PLUGIN_PATH=/usr/lib/mumble" \
    INCLUDEPATH+="/usr/include/speech-dispatcher" \
    LIBS+="-lpng16 -lfreetype -lXrender -lfontconfig"
  make release
}

package() {
  cd "$srcdir"/$pkgname-$pkgver

  # bin stuff
  install -m755 -D ./release/mumble "$pkgdir"/usr/bin/mumble
  install -m755 -D ./scripts/mumble-overlay "$pkgdir"/usr/bin/mumble-overlay

  # lib stuff
  install -m755 -D ./release/libmumble.so.$pkgver "$pkgdir"/usr/lib/mumble/libmumble.so.$pkgver
  ln -s libmumble.so.$pkgver "$pkgdir"/usr/lib/mumble/libmumble.so
  ln -s libmumble.so.$pkgver "$pkgdir"/usr/lib/mumble/libmumble.so.1
  ln -s libmumble.so.$pkgver "$pkgdir"/usr/lib/mumble/libmumble.so.1.3
  install -m755 -D ./release/plugins/liblink.so "$pkgdir"/usr/lib/mumble/liblink.so
  install -m755 -D ./release/libcelt* "$pkgdir"/usr/lib/mumble/

  # other stuff
  install -m644 -D ./scripts/mumble.desktop "$pkgdir"/usr/share/applications/mumble.desktop
  install -m755 -d "$pkgdir"/usr/share/man/man1
  install -m644 -D ./man/mum* "$pkgdir"/usr/share/man/man1/
  install -m644 -D ./icons/mumble.svg "$pkgdir"/usr/share/icons/hicolor/scalable/apps/mumble.svg
  install -m644 -D ./LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
# vim: sw=2:ts=2 et:
