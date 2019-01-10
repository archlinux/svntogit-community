# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Kaiting Chen <kaitocracy@gmail.com>
# Contributor: Abhishek Dasgupta <abhidg@gmail.com>
# Contributor: Eric Belanger <eric@archlinux.org>
# Contributor: Jan Fader <jan.fader@web.de>

pkgname=fish
pkgver=3.0.0
pkgrel=1
pkgdesc='Smart and user friendly shell intended mostly for interactive use'
url='https://fishshell.com/'
arch=('x86_64')
license=('GPL2')
depends=('bc' 'gcc-libs' 'inetutils' 'ncurses' 'which' 'pcre2')
optdepends=('python: for manual page completion parser and web configuration tool')
makedepends=('doxygen')
install=fish.install
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/fish-shell/fish-shell/archive/${pkgver}.tar.gz)
sha512sums=('97efb67c34860794787b44c04fbb8ebc1b7a8c37da00e7f6d93daab6707f198a2e0455e956a3b1c6a0c1711fa2d0f024ba42a3f82fbb17e857c518a858bb2ffb')

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
