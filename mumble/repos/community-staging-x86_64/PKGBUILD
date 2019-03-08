# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Lauri Niskanen <ape@ape3000.com>
# Contributor: Sebastian.Salich@gmx.de
# Contributor: Doc Angelo

# If you want support for your G15 Keyboard, please add 'g15daemon'
# to the depends and delete "no-g15" in the configure line below

pkgname=mumble
pkgver=1.2.19
pkgrel=13
arch=('x86_64')
pkgdesc="A voice chat application similar to TeamSpeak"
license=('BSD')
depends=('qt4' 'speex' 'lsb-release' 'libxi' 'avahi' 'libsndfile' 'protobuf' 'libpulse' 'opus'
         'xdg-utils' 'libspeechd' 'libpng' 'freetype2' 'fontconfig' 'libxrender')
makedepends=('boost' 'mesa')
optdepends=('speech-dispatcher')
url="https://www.mumble.info/"
source=(https://github.com/mumble-voip/mumble/releases/download/${pkgver}/mumble-${pkgver}.tar.gz{,.sig}
        https://github.com/mumble-voip/mumble/commit/ea861fe86743c8402bbad77d8d1dd9de8dce447e.patch
        mumble-protobuf-3.7.patch)
sha512sums=('f91111194a899149b500a94afcf7cc5b9691c7ce8669f07fca2c66adbb3916ddb863bf703d04fb8387133fb75f3c8edb52974d1acf3febfafa1f73da19946de4'
            'SKIP'
            'fcdaf2a3575e3871fe4003b93364a70a7c7029beb64ba5e24931abbe3898b72791848b5cf78ccf48eee5942a37f696a5134d061c2b8d60b66913abd701758330'
            'f83759c8e9dec47015c9c5c9023cb7c0501fd291309ee0dfc714f4fc9fdfa5c8728c9faaf129132f45d10577d6c843d544a71fe21f11ad3e9d31a61a58d68e95')
validpgpkeys=('C4666C6767A26017CE68406988048D0D625297A0') # Mumble Automatic Build Infrastructure 2017 <mumble-auto-build-2017@mumble.info>

prepare() {
  cd "$srcdir"/$pkgname-$pkgver

  # https://github.com/mumble-voip/mumble/pull/3287
  patch -p1 < ../ea861fe86743c8402bbad77d8d1dd9de8dce447e.patch
  patch -p1 -i ../mumble-protobuf-3.7.patch # Fix build with protobuf 3.7
}

build() {
  cd "$srcdir"/$pkgname-$pkgver

  # Building mumble
  qmake-qt4 main.pro \
    CONFIG+="c++11 bundled-celt no-bundled-opus no-bundled-speex no-g15 no-xevie no-server \
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
  ln -s libmumble.so.$pkgver "$pkgdir"/usr/lib/mumble/libmumble.so.1.2
  install -m755 -D ./release/plugins/liblink.so "$pkgdir"/usr/lib/mumble/liblink.so
  install -m755 -D ./release/plugins/libmanual.so "$pkgdir"/usr/lib/mumble/libmanual.so
  install -m755 -D ./release/libcelt* "$pkgdir"/usr/lib/mumble/

  # other stuff
  install -m644 -D ./scripts/mumble.desktop "$pkgdir"/usr/share/applications/mumble.desktop
  install -m755 -d "$pkgdir"/usr/share/man/man1
  install -m644 -D ./man/mum* "$pkgdir"/usr/share/man/man1/
  install -m644 -D ./icons/mumble.svg "$pkgdir"/usr/share/icons/hicolor/scalable/apps/mumble.svg
  install -m644 -D ./LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
# vim: sw=2:ts=2 et:
