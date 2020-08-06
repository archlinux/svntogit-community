# Maintainer: schuay <jakob.gruber@gmail.com>
# Maintainer: Maxime Gauduin <alucryd@archlinux.org>
# Contributor: Jeremy Newton (Mystro256) <alexjnewt@gmail.com>

pkgname=dolphin-emu
pkgver=5.0.r12380.afd25de85e
pkgrel=1
epoch=1
pkgdesc='A Gamecube / Wii / Triforce emulator'
arch=(x86_64)
url=https://dolphin-emu.org
license=(GPL2)
depends=(
  alsa-lib
  bluez-libs
  enet
  gcc-libs
  glibc
  hidapi
  libavcodec.so
  libavformat.so
  libavutil.so
  libcurl.so
  libevdev
  libgl
  libminiupnpc.so
  libpng
  libpulse
  libswscale.so
  libudev.so
  libusb-1.0.so
  libx11
  libxi
  libxrandr
  lzo
  mbedtls
  pugixml
  qt5-base
  sfml
  zlib
)
makedepends=(
  cmake
  git
  python
)
optdepends=('pulseaudio: PulseAudio backend')
options=(!emptydirs)
_commit=afd25de85ef836ca376d84062e48674d2a5218d9
source=(dolphin-emu::git+https://github.com/dolphin-emu/dolphin.git#commit=${_commit})
sha256sums=(SKIP)

pkgver() {
  cd dolphin-emu

  git describe | sed 's/-/.r/; s/-g/./'
}

build() {
  cmake -S dolphin-emu -B build \
    -DCMAKE_BUILD_TYPE=None \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DUSE_SHARED_ENET=ON \
    -DDISTRIBUTOR=archlinux.org
  make -C build
}

package() {
  make DESTDIR="${pkgdir}" -C build install
  install -Dm 644 dolphin-emu/Data/51-usb-device.rules -t "${pkgdir}"/usr/lib/udev/rules.d/
  rm -rf "${pkgdir}"/usr/{include,lib/libdiscord-rpc.a}
}

# vim: ts=2 sw=2 et:
