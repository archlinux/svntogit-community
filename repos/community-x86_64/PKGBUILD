# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Ray Rashif <schiv@archlinux.org>
# Contributor: Limao Luo <luolimao+AUR@gmail.com>
# Contributor: Sebastien Luttringer <seblu+arch@seblu.net>
# Contributor: Jochen Immendœrfer <jochen.immendoerfer@gmail.com>

pkgname=alsa-tools
pkgver=1.2.5
pkgrel=2
pkgdesc="Advanced tools for certain sound cards"
arch=(x86_64)
url="https://alsa-project.org/"
license=(GPL2)
depends=(
  gcc-libs
  glibc
)
makedepends=(
  alsa-lib
  fltk
  gtk2
  gtk3
)
optdepends=(
  'fltk: hdspconf, hdspmixer'
  'gtk2: envy24control, echomixer, rmeddigicontrol'
  'gtk3: hdajackretask'
  'python-pyalsa: hwmixvolume'
  'python-gobject: hwmixvolume'
)
provides=($pkgname-emu10k1 $pkgname-ice1712 liblo10k1.so)
source=(https://www.alsa-project.org/files/pub/tools/$pkgname-$pkgver.tar.bz2{,.sig})
sha512sums=('1c4ff947d9f2424056a6748e04a1250fb73443a3f470f61d0b563c91be082bc42d56e550d6cc27eaed3edcea2066a107e20455c959b053b5deafa2d811b7e498'
            'SKIP')
b2sums=('1ecd7d24771e3f5899a7084a69196c9301b549dd331cbbbc55b6f0c694566147a9d5642cf94f0ad5ca5fcedb77daa1cb4615ce0ec0be157b32c9d756611a7cca'
        'SKIP')
validpgpkeys=('F04DF50737AC1A884C4B3D718380596DA6E59C91') # ALSA Release Team (Package Signing Key v1) <release@alsa-project.org>

_tools=(
  as10k1
  echomixer
  envy24control
  hda-verb
  hdajackretask
  hdajacksensetest
  hdspconf
  hdsploader
  hdspmixer
  hwmixvolume
  ld10k1
  mixartloader
  pcxhrloader
  # qlo10k1  # disabled, because build is broken
  rmedigicontrol
  sb16_csp
  seq/sbiload
  sscape_ctl
  vxloader
  us428control
  usx2yloader
)

prepare() {
  for tool in "${_tools[@]}"; do
    (
      cd $pkgname-$pkgver/$tool
      autoreconf -vfi
    )
  done
}

build() {
  # not using upstream's global makefile as it's trying to be too clever
  for tool in "${_tools[@]}"; do
    (
      cd $pkgname-$pkgver/$tool
      ./configure --prefix=/usr --sbindir=/usr/bin
      make
    )
  done
}

package() {
  depends+=(
    alsa-lib libasound.so
  )

  for tool in "${_tools[@]}"; do
    make DESTDIR="$pkgdir" install -C $pkgname-$pkgver/$tool
  done
}

# vim:set ts=2 sw=2 et:
