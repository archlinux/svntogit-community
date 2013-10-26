# Maintainer: schuay <jakob.gruber@gmail.com>
# Contributor: Jeremy Newton (Mystro256)

pkgname=dolphin-emu
pkgver=4.0.1
pkgrel=1
epoch=1
pkgdesc='A Gamecube / Wii / Triforce emulator'
arch=('i686' 'x86_64')
url='http://dolphin-emu.org'
license=('GPL2')

makedepends=('cmake' 'git' 'opencl-headers')
depends=('bluez-libs' 'ffmpeg' 'glew' 'libao' 'miniupnpc' 'openal' 'portaudio' 'sdl2' 'soundtouch' 'wxgtk2.9')
optdepends=('pulseaudio: PulseAudio backend')

source=("${pkgname%-*}::git+https://code.google.com/p/dolphin-emu/#tag=${pkgver}"
        'dolphin-emu.desktop'
        'Dolphin_Logo.png')

# TODO: Drop the custom icon and .desktop file, apparently dolphin ships these now.

build() {
  cd "${srcdir}/${pkgname%-*}"

  mkdir build && cd build
  cmake .. -DCMAKE_INSTALL_PREFIX=/usr -DwxWidgets_CONFIG_EXECUTABLE=/usr/bin/wx-config-2.9
  make
}

package() {
  cd "${srcdir}/${pkgname%-*}/build"

  make DESTDIR=${pkgdir} install

  install -Dm644 "${srcdir}/dolphin-emu.desktop" \
                 "${pkgdir}/usr/share/applications/dolphin-emu.desktop"
  install -Dm644 "${srcdir}/Dolphin_Logo.png" "${pkgdir}/usr/share/pixmaps/dolphin-emu.png"
}

md5sums=('SKIP'
         'feed4580c2e6bfbc7f6c67dad861daae'
         'd15c51f547b4bd47e510faac40bcc9d6')
