# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: David Runge <dvzrv@archlinux.org>
# Contributor: Lauri Niskanen <ape@ape3000.com>
# Contributor: Sebastian.Salich@gmx.de
# Contributor: Doc Angelo

pkgbase=mumble
pkgname=('mumble' 'murmur')
pkgver=1.3.4
pkgrel=7
pkgdesc="An Open Source, low-latency, high quality voice chat software"
arch=('x86_64')
url="https://www.mumble.info/"
license=('BSD')
# shared depends
depends=('gcc-libs' 'glibc' 'lsb-release' 'openssl' 'qt5-base')
# shared makedepends
makedepends=('avahi' 'boost' 'protobuf' 'python' 'qt5-tools')
# mumble makedepends
makedepends+=('alsa-lib' 'hicolor-icon-theme' 'jack' 'libpulse' 'libsndfile'
'libspeechd' 'libx11' 'libxi' 'mesa' 'opus' 'qt5-svg' 'speex' 'xdg-utils')
# murmur makedepends
makedepends+=('grpc' 'libcap' 'zeroc-ice')
source=("https://github.com/mumble-voip/mumble/releases/download/${pkgver}/mumble-${pkgver}.tar.gz"{,.sig}
        "0001-Added-DBus-calls-to-activate-and-deactivate-push-to-talk.patch"
        "murmur.dbus.conf"
        "murmur.service"
        "murmur.sysusers"
        "murmur.tmpfiles")
sha512sums=('e2dde5aad30d1a931e7acd8d7db0b8c785d3a268d0b8cf5626fa03953a51bcadb719c6682c440d02524e83beee13d73d8f5bb3fdf98ab1c82d3ecf824cc25f68'
            'SKIP'
            'ca751eb688e9de88064e2e11f155b4c69a55c9464fcd839ad8ce834af7e444a5683be62700fe7e6e7a60a5de37c0dc48575bb81d633607974e0f41d05b6a51be'
            '97c7effdddec324e40195c36ef4927950a5de26d2ee2d268d89df6fb547207bbbe30292773316cae6f57ec9923244f205fb0edc377b798771ba7385e3c11d86a'
            '2059eeac32cc078168a2ea56fe3034df69814516303adeffb8062c7b90a88177a536e6a6742196ee90370084d4e536f825b1744f8bed2bb704159a8a8bccb606'
            '5af28d0c2b2b072cfbd500b5f63549e88a86cf3fc15e4d2df89e787c4d2bafdecbe078a518e0d1b25d82f9873cb06838ec1c9ebed625ffb7e8c80fcd942ebf74'
            '411784e8e0dcf6c163780ae895ae1a6bdad0bb2dd2b128911c484ac3eff073d95c5791b625493a2b8296d24bd7e6ac72d3c42180817e48b29f0c6a8fd841807c')
b2sums=('bcde3fd859ec4faea06f996cd4c583af7c0b8409cca79cb05ef8ba7fcdeac9e49ed1d07a4131225dd582da7610190d4006abc731fd4276b2288e02e8c18effb6'
        'SKIP'
        'cb8d25c0e6e46a5d85c61b04586293180bf1804296aa338c8c67e05817fec41965eb46e44dab2f4c5bec24e29e08a8f6eb645500c7b6c0d63ce31f2f09c75250'
        'a416d071d9658fc3f3ea267d6ff24237317f5c05b59fe1578e5a4cb4911840896bf5e524a143f5c70a797da9f343312468720f03343b4b66bea20e94aa316cc2'
        'd3ff1099c98ccb01cb96608c9ce328b654fe8f6c1922cdb602223ba66267655b569b7113ad24820e37989448695b874872279d49f94d44ab569a228cf545498f'
        '9909371a0d1c06d2aa00f161aebb19266aad0253b407dd01da5325f4f307678bba28a89596bd2ec97df5844068856c10bb4b10acad7bf170dd2853b3e11c48cd'
        '999b2848c718f25a2d8257595194521e08d36d101906d76b137218f0a19f2451b7e1adc0c013e1f1c3448145b89a1e88f46cb1c9da27777737379227d3574d10')
# See https://github.com/mumble-voip/mumble-gpg-signatures
validpgpkeys=('6A24D225AAE02DD6352C3D269F179B6BF48ADF25') # Mumble Automatic Build Infrastructure 2021 <mumble-auto-build-2021@mumble.info>

prepare() {
  cd "${pkgbase}-${pkgver}"
  # set default configuration for murmur
  sed -e "1i; vi:ft=cfg" \
      -e "s|database=|database=/var/db/murmur/murmur.sqlite|" \
      -e "s|;logfile=murmur.log|logfile=|" \
      -e "s|;uname=|uname=murmur|" \
      -i scripts/murmur.ini

  patch -Np1 -i "$srcdir"/0001-Added-DBus-calls-to-activate-and-deactivate-push-to-talk.patch
}

build() {
  cd "$pkgname-$pkgver"
  # build mumble
  qmake-qt5 main.pro \
    CONFIG+="no-bundled-opus no-bundled-speex no-g15 no-xevie no-server \
    no-embed-qt-translations no-update packaged" \
    DEFINES+="PLUGIN_PATH=/usr/lib/mumble" \
    INCLUDEPATH+="/usr/include/speech-dispatcher"
  make release
  # build murmur
  qmake-qt5 main.pro CONFIG+="no-client grpc"
  make release
}

package_mumble() {
  pkgdesc+=" (client)"
  # NOTE: opus is dlopen'ed
  depends+=('hicolor-icon-theme' 'libasound.so' 'libdns_sd.so' 'libjack.so'
  'libprotobuf.so' 'libpulse.so' 'libsndfile.so' 'libspeechd' 'libx11' 'libxi'
  'opus' 'qt5-svg' 'speex' 'xdg-utils')
  optdepends=('speech-dispatcher: Text-to-speech support'
              'espeak-ng: Text-to-speech support')

  cd "$pkgbase-$pkgver"
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
  # AppStream metadata
  install -vDm 644 scripts/mumble.appdata.xml -t "$pkgdir/usr/share/metainfo"
  # man page
  install -vDm 644 "man/${pkgname}"*.1 -t "$pkgdir/usr/share/man/man1/"
  # XDG desktop icons
  install -vDm 644 icons/mumble.svg -t "$pkgdir/usr/share/icons/hicolor/scalable/apps/"
  # license
  install -vDm 644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname"
}

package_murmur() {
  pkgdesc+=" (server)"
  depends+=('grpc' 'libcap.so' 'libdns_sd.so' 'libprotobuf.so' 'zeroc-ice')
  backup=("etc/murmur.ini")
  install="murmur.install"

  cd "${pkgbase}-${pkgver}"
  # murmur has no install target: https://github.com/mumble-voip/mumble/issues/1029
  install -vDm 755 release/murmurd -t "${pkgdir}"/usr/bin
  install -vDm 640 scripts/murmur.ini -t "${pkgdir}"/etc
  install -vDm 644 "${srcdir}"/murmur.dbus.conf "${pkgdir}"/usr/share/dbus-1/system.d/murmur.conf
  install -vDm 644 README -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -vDm 644 man/murmur*.1 -t "${pkgdir}/usr/share/man/man1/"
  install -vDm 644 "${srcdir}"/murmur.service -t "${pkgdir}/usr/lib/systemd/system/"
  install -vDm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -vDm 644 "${srcdir}"/murmur.sysusers "${pkgdir}/usr/lib/sysusers.d/${pkgname}.conf"
  install -vDm 644 "${srcdir}"/murmur.tmpfiles "${pkgdir}/usr/lib/tmpfiles.d/${pkgname}.conf"
  install -vDm 644 src/murmur/{Murmur.ice,MurmurRPC.proto} -t "${pkgdir}/usr/share/${pkgname}"
}
# vim: sw=2:ts=2 et:
