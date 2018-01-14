# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Kaiting Chen <kaitocracy@gmail.com>
# Contributor: Abhishek Dasgupta <abhidg@gmail.com>
# Contributor: Eric Belanger <eric@archlinux.org>
# Contributor: Jan Fader <jan.fader@web.de>

pkgname=fish
pkgver=2.7.1
pkgrel=1
pkgdesc='Smart and user friendly shell intended mostly for interactive use'
url='https://fishshell.com/'
arch=('x86_64')
license=('GPL2')
depends=('bc' 'gcc-libs' 'inetutils' 'ncurses' 'which')
optdepends=('python: for manual page completion parser and web configuration tool')
makedepends=('doxygen')
install=fish.install
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/fish-shell/fish-shell/archive/${pkgver}.tar.gz)
sha512sums=('53eb8082812f28386b491ea18caa4a51ac66ead87fa78d5584275c66f1335b8705fad266170dc2ed6ee9e5d1febcdf0869c37ed2f95b58c10a74faf4ad95e610')

prepare() {
  cd fish-shell-${pkgver}
  echo ${pkgver} > version
  autoreconf -fiv
}

build() {
  cd fish-shell-${pkgver}
  ./configure --prefix=/usr \
    --sysconfdir=/etc
  make
}

package() {
  cd fish-shell-${pkgver}
  make DESTDIR="${pkgdir}" install
}

# vim: ts=2 sw=2 et:
