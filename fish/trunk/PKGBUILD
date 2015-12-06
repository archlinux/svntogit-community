# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Kaiting Chen <kaitocracy@gmail.com>
# Contributor: Abhishek Dasgupta <abhidg@gmail.com>
# Contributor: Eric Belanger <eric@archlinux.org>
# Contributor: Jan Fader <jan.fader@web.de>

pkgname=fish
pkgver=2.2.0
pkgrel=5
pkgdesc='Smart and user friendly shell intended mostly for interactive use'
url='http://fishshell.com/'
arch=('i686' 'x86_64')
license=('GPL2')
depends=('bc' 'gcc-libs' 'inetutils' 'ncurses' 'which')
optdepends=('python: for manual page completion parser and web configuration tool')
makedepends=('doxygen')
install=fish.install
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/fish-shell/fish-shell/archive/${pkgver}.tar.gz)
sha512sums=('a1108a8d5c96bcac1b1ced74e6f28287094fa68f28756811f6a6604bde2b4de88d7637da21874b602723fce129a407be7e24affecab468997158442af208308a')

prepare() {
  cd fish-shell-${pkgver}
  echo ${pkgver} > version
  autoconf -i
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

# vim:set ts=2 sw=2 et:
