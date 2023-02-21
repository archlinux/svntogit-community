# Maintainer: schuay <jakob.gruber@gmail.com>
# Maintainer: Maxime Gauduin <alucryd@archlinux.org>
# Contributor: Jeremy Newton (Mystro256) <alexjnewt@gmail.com>

pkgname=dolphin-emu
pkgver=5.0.r18498.46b99671d9
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
  libfmt.so
  libgl
  libmgba
  libminiupnpc.so
  libpulse
  libswscale.so
  libudev.so
  libusb-1.0.so
  libx11
  libxi
  libxrandr
  lzo
  mbedtls
  minizip-ng
  pugixml
  qt6-base
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
_commit=46b99671d9158e0ca840c1d8ef249db0f321ced7
source=(
  dolphin-emu::git+https://github.com/dolphin-emu/dolphin.git#commit=${_commit}
  git+https://github.com/mozilla/cubeb.git
  git+https://github.com/epezent/implot.git
  git+https://github.com/randy408/libspng.git
  git+https://github.com/arsenm/sanitizers-cmake.git
  git+https://github.com/KhronosGroup/SPIRV-Cross.git
  git+https://github.com/GPUOpen-LibrariesAndSDKs/VulkanMemoryAllocator.git
  git+https://github.com/zlib-ng/zlib-ng.git
)
b2sums=('SKIP'
        'SKIP'
        'SKIP'
        'SKIP'
        'SKIP'
        'SKIP'
        'SKIP'
        'SKIP')

prepare() {
  cd dolphin-emu
  for submodule in Externals/{cubeb/cubeb,implot/implot,libspng/libspng,spirv_cross/SPIRV-Cross,VulkanMemoryAllocator,zlib-ng/zlib-ng}; do
    git submodule init ${submodule}
    git config submodule.${submodule}.url ../${submodule##*/}
    git -c protocol.file.allow=always submodule update ${submodule}
  done
  cd Externals/cubeb/cubeb
  git submodule init cmake/sanitizers-cmake
  git config submodule.cmake/sanitizers-cmake.url "${srcdir}"/sanitizers-cmake
  git -c protocol.file.allow=always submodule update cmake/sanitizers-cmake
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
    -DENABLE_TESTS=OFF \
    -DUSE_MGBA=ON \
    -DUSE_SHARED_ENET=ON \
    -Wno-dev
  cmake --build build
}

package() {
  DESTDIR="${pkgdir}" cmake --install build
  install -Dm 644 dolphin-emu/Data/51-usb-device.rules -t "${pkgdir}"/usr/lib/udev/rules.d/
  rm -rf "${pkgdir}"/usr/{include,lib/libdiscord-rpc.a}
}

# vim: ts=2 sw=2 et:
