# Maintainer: Doug Newgard <scimmia at archlinux dot info>
# Contributor: Andrey Mivrenik <gim at fastmail dot fm>
# Contributor: Glen Oakley <goakley123@gmail.com>

pkgname=cool-retro-term
pkgver=1.0.0
pkgrel=2
pkgdesc='A good looking terminal emulator which mimics the old cathode display'
arch=('i686' 'x86_64')
url='https://github.com/Swordfish90/cool-retro-term'
license=('GPL3')
depends=('qmltermwidget' 'qt5-quickcontrols' 'qt5-graphicaleffects' 'hicolor-icon-theme')
install=$pkgname.install
source=("https://github.com/Swordfish90/cool-retro-term/archive/v$pkgver.tar.gz")
sha256sums=('db799084680545b6961e1b3d1bb7ff0cb8105e82279fe734c2c07c32525350d9')

prepare() {
  cd "$srcdir/$pkgname-$pkgver"

  sed -i '/qmltermwidget/d' cool-retro-term.pro
}

build() {
  cd "$srcdir/$pkgname-$pkgver"

  qmake
  make
}

package() {
  cd "$srcdir/$pkgname-$pkgver"

  make INSTALL_ROOT="$pkgdir" install
}
