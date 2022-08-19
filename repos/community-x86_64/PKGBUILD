# Maintainer: Maxime Gauduin <alucryd@archlinux.org>
# Contributor: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: Aaron Plattner <aplattner@nvidia.com>
# Contributor: Bart Verhoeven <bartverhoeven@live.com>

pkgname=vdpauinfo
pkgver=1.5
pkgrel=1
pkgdesc='Command line utility for querying the capabilities of a VDPAU device'
arch=(x86_64)
url=https://gitlab.freedesktop.org/vdpau/vdpauinfo
license=(custom)
depends=(
  gcc-libs
  libvdpau
  libx11
)
makedepends=(git)
_tag=a0dd9710e499a1a4ac5f273daf7ebe9e159f3e78
source=(git+https://gitlab.freedesktop.org/vdpau/vdpauinfo.git#tag=${_tag})
validpgpkeys=(BD68A042C603DDAD9AA354B0F56ACC8F09BA9635) # Aaron Plattner <aplattner@nvidia.com>
sha256sums=(SKIP)

pkgver() {
  cd vdpauinfo
  git describe --tags
}

prepare() {
  cd vdpauinfo
  autoreconf -fiv
}

build() {
  cd vdpauinfo
  ./configure \
    --prefix=/usr
  make
}

package() {
  make DESTDIR="${pkgdir}" -C vdpauinfo install
  install -Dm 644 vdpauinfo/COPYING -t "$pkgdir"/usr/share/licenses/vdpauinfo/
}

# vim: ts=2 sw=2 et:
