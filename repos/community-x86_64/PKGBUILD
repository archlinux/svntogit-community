# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Kaiting Chen <kaitocracy@gmail.com>
# Contributor: Abhishek Dasgupta <abhidg@gmail.com>
# Contributor: Eric Belanger <eric@archlinux.org>
# Contributor: Jan Fader <jan.fader@web.de>

pkgname=fish
pkgver=2.6.0
pkgrel=1
pkgdesc='Smart and user friendly shell intended mostly for interactive use'
url='http://fishshell.com/'
arch=('i686' 'x86_64')
license=('GPL2')
depends=('bc' 'gcc-libs' 'inetutils' 'ncurses' 'which')
optdepends=('python: for manual page completion parser and web configuration tool')
makedepends=('doxygen')
install=fish.install
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/fish-shell/fish-shell/archive/${pkgver}.tar.gz)
sha512sums=('9ee9dbfee84af142c152b7b33c66aa930400e789776f38767f24c36ef0fa93d5939f6c1be0f17e01231b588d0cdc4dd622257bd61043e576de495cda0d61067c')

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
