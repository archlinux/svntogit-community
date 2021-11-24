# Maintainer: schuay <jakob.gruber@gmail.com>
# Maintainer: Maxime Gauduin <alucryd@archlinux.org>
# Contributor: Jeremy Newton (Mystro256) <alexjnewt@gmail.com>

pkgname=dolphin-emu
pkgver=5.0.r15445.db02b50d2e
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
  #libmgba
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
  ninja
  python
)
optdepends=('pulseaudio: PulseAudio backend')
options=(!emptydirs)
_commit=db02b50d2ecdfbbc21e19aadc57253c353069f77
source=(
  dolphin-emu::git+https://github.com/dolphin-emu/dolphin.git#commit=${_commit}
  dolphin-emu-system-libmgba.patch
)
b2sums=('SKIP'
        '004692abcfa3a0a10996afba3a8fe71627300224a6f96cc5b6c6183c32d5f7bd1ece36775cd2642a0c4d7fc9225f72da39063cc68ff089e8d01685a2fbbd6957')

prepare() {
  cd dolphin-emu
  #patch -Np1 -i ../dolphin-emu-system-libmgba.patch
}

pkgver() {
  cd dolphin-emu
  git describe | sed 's/-/.r/; s/-g/./'
}

build() {
  cmake -S dolphin-emu -B build -G Ninja \
    -DCMAKE_BUILD_TYPE=None \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DDISTRIBUTOR=archlinux.org \
    -DUSE_MGBA=OFF \
    -DUSE_SHARED_ENET=ON
  cmake --build build
}

package() {
  DESTDIR="${pkgdir}" cmake --install build
  install -Dm 644 dolphin-emu/Data/51-usb-device.rules -t "${pkgdir}"/usr/lib/udev/rules.d/
  rm -rf "${pkgdir}"/usr/{include,lib/libdiscord-rpc.a}
}

# vim: ts=2 sw=2 et:
