# Maintainer: Antoine Damhet <antoine.damhet@lse.epita.fr>

pkgname=brightnessctl
pkgver=0.5.1
pkgrel=1
pkgdesc="Lightweight brightness control tool"
arch=('x86_64')
url='https://github.com/Hummer12007/brightnessctl'
license=('MIT')
source=(
  "${pkgname}-${pkgver}.tar.gz::https://github.com/Hummer12007/brightnessctl/archive/${pkgver}.tar.gz"
)
sha512sums=('41ac86357b3b5a3d54a043140a6bdb1fb68d5080a16e86692059ad58f4b9134a8532432a3f664c70c665a4ad73ea8a94cc9b88fa84abc28f0356b8b397aaebc7')
install='brightnessctl.install'

build() {
  cd "${pkgname}-${pkgver}"
  make
}

package() {
  cd "${pkgname}-${pkgver}"
  make UDEVDIR="/usr/lib/udev/rules.d" INSTALL_UDEV_RULES=1 DESTDIR="$pkgdir" install

  mkdir -p "${pkgdir}/usr/share/licenses/${pkgname}"
  install -m 0644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/"
}

# vim:set ts=2 sw=2 et:
