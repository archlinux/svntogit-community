# Maintainer: schuay <jakob.gruber@gmail.com>
# Contributor: Jeremy Newton (Mystro256)

pkgname=dolphin-emu
pkgver=3.5
pkgrel=3
epoch=1
pkgdesc='A Gamecube / Wii / Triforce Emulator'
arch=('i686' 'x86_64')
url='http://dolphin-emu.org'
license=('GPL2')

makedepends=('cmake' 'glproto' 'opencl-headers')
depends=('bluez' 'ffmpeg' 'glew' 'libao' 'libgl' 'libxxf86vm' 'lsb-release' 'lzo2' 'mesa' \
         'nvidia-cg-toolkit' 'openal' 'portaudio' 'sdl' 'wxgtk2.9')
optdepends=('pulseaudio')

source=("http://dolphin-emu.googlecode.com/files/dolphin-${pkgver}-src.zip"
        'dolphin-emu.desktop'
        'Dolphin_Logo.png')

build() {
  cd "${srcdir}/dolphin-${pkgver}"

  mkdir build && cd build
  cmake .. -DCMAKE_INSTALL_PREFIX=/usr -DwxWidgets_CONFIG_EXECUTABLE=/usr/bin/wx-config-2.9
  make
}

package() {
  cd "${srcdir}/dolphin-${pkgver}/build"

  make DESTDIR=${pkgdir} install

  install -Dm644 "${srcdir}/dolphin-emu.desktop" \
                 "${pkgdir}/usr/share/applications/dolphin-emu.desktop"
  install -Dm644 "${srcdir}/Dolphin_Logo.png" "${pkgdir}/usr/share/pixmaps/dolphin-emu.png"
}

md5sums=('4d0429f1e10f0862256e0b4c4e2f44a3'
         'feed4580c2e6bfbc7f6c67dad861daae'
         'd15c51f547b4bd47e510faac40bcc9d6')
