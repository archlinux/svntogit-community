# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Kaiting Chen <kaitocracy@gmail.com>
# Contributor: Abhishek Dasgupta <abhidg@gmail.com>
# Contributor: Eric Belanger <eric@archlinux.org>
# Contributor: Jan Fader <jan.fader@web.de>

pkgname=fish
pkgver=2.7.0
pkgrel=1
pkgdesc='Smart and user friendly shell intended mostly for interactive use'
url='http://fishshell.com/'
arch=('x86_64')
license=('GPL2')
depends=('bc' 'gcc-libs' 'inetutils' 'ncurses' 'which')
optdepends=('python: for manual page completion parser and web configuration tool')
makedepends=('doxygen')
install=fish.install
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/fish-shell/fish-shell/archive/${pkgver}.tar.gz)
sha512sums=('c2006dec05e0398c88a5d627017243e8bffefa0e48415b1242487f211f3948ba9fdd849502630f0f02823ad5263358d14588b8dc812947a21f22ed6fe3542d93')

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
