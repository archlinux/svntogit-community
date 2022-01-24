# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: David Runge <dvzrv@archlinux.org>
# Contributor: Lauri Niskanen <ape@ape3000.com>
# Contributor: Sebastian.Salich@gmx.de
# Contributor: Doc Angelo

pkgbase=mumble
pkgname=('mumble' 'murmur')
pkgver=1.4.230
pkgrel=1
pkgdesc="An Open Source, low-latency, high quality voice chat software"
arch=('x86_64')
url="https://www.mumble.info/"
license=('BSD')
# shared depends
depends=('gcc-libs' 'glibc' 'lsb-release' 'openssl' 'qt5-base')
# shared makedepends
makedepends=('avahi' 'boost' 'cmake' 'poco' 'protobuf' 'python' 'qt5-tools' 'speech-dispatcher')
# mumble makedepends
makedepends+=('alsa-lib' 'hicolor-icon-theme' 'jack' 'libpulse' 'libsndfile'
'libspeechd' 'libx11' 'libxi' 'mesa' 'opus' 'qt5-svg' 'speex' 'xdg-utils')
# murmur makedepends
makedepends+=('grpc' 'libcap' 'zeroc-ice')
source=(
  "https://github.com/mumble-voip/mumble/releases/download/v${pkgver}/mumble-${pkgver}.tar.gz"{,.sig}
  "murmur.dbus.conf"
  "murmur.service"
  "murmur.sysusers"
  "murmur.tmpfiles"
  "${pkgname}-1.4.230-configuration.patch"
)
sha512sums=('6cffc7a95d88b33876f4093b99266468210f5c14f190fbd2fbe4991bef91a567e55296e7c8c6cc99e19c054853211085cc3cc08109e367e6776afb70766b3a53'
            'SKIP'
            '97c7effdddec324e40195c36ef4927950a5de26d2ee2d268d89df6fb547207bbbe30292773316cae6f57ec9923244f205fb0edc377b798771ba7385e3c11d86a'
            'd080821eda9fc8eb49eb6536e333de7fff1be44ccf501ada086f684c96faf5da25aad1ff15465524f928e65b89c3c5b032167ff1a3d5971e269d4d1b093a1d62'
            '5af28d0c2b2b072cfbd500b5f63549e88a86cf3fc15e4d2df89e787c4d2bafdecbe078a518e0d1b25d82f9873cb06838ec1c9ebed625ffb7e8c80fcd942ebf74'
            '411784e8e0dcf6c163780ae895ae1a6bdad0bb2dd2b128911c484ac3eff073d95c5791b625493a2b8296d24bd7e6ac72d3c42180817e48b29f0c6a8fd841807c'
            'e35dee4ce1cca15747330ba21892064adec85feb9937a89aea95ccf2c668746075fbe1c343e26ba2ac26a9e36144fb0b3eb0f44d85e6d258040bcd3500818a31')
b2sums=('da433f3c15d7e45dfac0c8a78c9dbe86ba8d5cd078d2d87fd4d90718968fc9e5928c3c5c5ba2e40a8a54d02a646c5fc6a7ee2fff4b71dfa411d74f395b097c26'
        'SKIP'
        'a416d071d9658fc3f3ea267d6ff24237317f5c05b59fe1578e5a4cb4911840896bf5e524a143f5c70a797da9f343312468720f03343b4b66bea20e94aa316cc2'
        '00d452eb3a8892e7b818083365ba6785ea82adf948caa4b93dcbb814e867b8207251455c1df8c0af67a85048270c5d736fde595e30cfd6ee858661862f97227c'
        '9909371a0d1c06d2aa00f161aebb19266aad0253b407dd01da5325f4f307678bba28a89596bd2ec97df5844068856c10bb4b10acad7bf170dd2853b3e11c48cd'
        '999b2848c718f25a2d8257595194521e08d36d101906d76b137218f0a19f2451b7e1adc0c013e1f1c3448145b89a1e88f46cb1c9da27777737379227d3574d10'
        'd77b81c5ac39561e3df087ad325e88909b083dad95a25c7106a941645354c87d07ea5d41eec5aa4a77a402cadbe8230a4a1c641d8414d11174e4b3254fc18647')
# See https://github.com/mumble-voip/mumble-gpg-signatures
validpgpkeys=(
'1EDEBE2A93CB97FA9903D52E25F63C66245DFC60'  # Mumble Automatic Build Infrastructure 2022 <mumble-auto-build-2022@mumble.info>
)

prepare() {
  cd "${pkgbase}-${pkgver}.src"
  patch -Np1 -i ../"${pkgname}-1.4.230-configuration.patch"
}

build() {
  cmake -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=None \
        -Dwarnings-as-errors=OFF \
        -Dbundled-opus=OFF \
        -Dbundled-speex=OFF \
        -Dupdate=OFF \
        -Dserver=OFF \
        -Wno-dev \
        -B build-client \
        -S "${pkgbase}-${pkgver}.src"
  make VERBOSE=1 -C build-client

  cmake -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=None \
        -Dwarnings-as-errors=OFF \
        -Dbundled-opus=OFF \
        -Dbundled-speex=OFF \
        -Dupdate=OFF \
        -Dclient=OFF \
        -Wno-dev \
        -B build-server \
        -S "${pkgbase}-${pkgver}.src"
  make VERBOSE=1 -C build-server
}

package_mumble() {
  pkgdesc+=" (client)"
  # NOTE: avahi, jack, libpulse, opus is dlopen'ed
  depends+=('avahi' 'hicolor-icon-theme' 'jack' 'libasound.so' 'libprotobuf.so'
  'libpulse' 'libsndfile.so' 'libspeechd' 'libx11' 'libxi' 'opus' 'poco'
  'qt5-svg' 'speex' 'xdg-utils')
  optdepends=(
    'lib32-glibc: for mumble-overlay'
    'espeak-ng: Text-to-speech support'
    'speech-dispatcher: Text-to-speech support'
  )

  make DESTDIR="${pkgdir}" install -C build-client
  install -vDm 644 "${pkgbase}-${pkgver}.src/LICENSE" -t "$pkgdir/usr/share/licenses/$pkgname"
}

package_murmur() {
  pkgdesc+=" (server)"
  # NOTE: avahi is dlopen'ed
  depends+=('avahi' 'grpc' 'libcap.so' 'libdns_sd.so' 'libprotobuf.so' 'zeroc-ice')
  backup=('etc/murmur.ini')
  install=murmur.install

  make DESTDIR="${pkgdir}" install -C build-server
  # renaming of the server component was not done in full capacity: https://github.com/mumble-voip/mumble/issues/5436
  mv -v "${pkgdir}/usr/bin/"{mumble-server,murmurd}

  (
    cd "${pkgbase}-${pkgver}.src"
    install -vDm 640 scripts/murmur.ini -t "${pkgdir}/etc"
    install -vDm 644 README.md -t "${pkgdir}/usr/share/doc/${pkgname}"
    install -vDm 644 man/murmur*.1 -t "${pkgdir}/usr/share/man/man1/"
    install -vDm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
    install -vDm 644 src/murmur/{Murmur.ice,MurmurRPC.proto} -t "${pkgdir}/usr/share/${pkgname}"
  )

  install -vDm 644 murmur.dbus.conf "${pkgdir}/usr/share/dbus-1/system.d/murmur.conf"
  install -vDm 644 murmur.service -t "${pkgdir}/usr/lib/systemd/system/"
  install -vDm 644 murmur.sysusers "${pkgdir}/usr/lib/sysusers.d/${pkgname}.conf"
  install -vDm 644 murmur.tmpfiles "${pkgdir}/usr/lib/tmpfiles.d/${pkgname}.conf"
}
# vim: sw=2:ts=2 et:
