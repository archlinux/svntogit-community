# $Id$
# Maintainer: speps <speps at aur dot archlinux dot org>

pkgname=jalv
pkgver=1.4.6
pkgrel=2
pkgdesc="A simple but fully featured LV2 host for Jack"
arch=('i686' 'x86_64')
url="http://drobilla.net/software/$pkgname/"
license=('custom:ISC')
depends=('lilv' 'suil')
makedepends=('python2' 'qt4' 'gtk2' 'gtk3' 'gtkmm')
optdepends=('qt4: Qt 4.x frontend'
            'gtk2: Gtk+ 2.x frontend'
            'gtk3: Gtk+ 3.x frontend'
            'gtkmm: Gtk++ 2.x frontend')
source=(http://download.drobilla.net/$pkgname-$pkgver.tar.bz2{,.sig})
md5sums=('8c11c58c4b0e69fb6b21041bcac275f7'
         'SKIP')
validpgpkeys=('907D226E7E13FA337F014A083672782A9BF368F3') # David Robillard

prepare() {
  cd $pkgname-$pkgver
  # use moc-qt4
  sed -i 's/moc/&-qt4/;s/${MOC}/moc-qt4/' wscript
}

build() {
  cd $pkgname-$pkgver
  CXXFLAGS+=' -std=c++11'
  python2 waf configure --prefix=/usr
  python2 waf
}

package() {
  cd $pkgname-$pkgver
  python2 waf install --destdir="$pkgdir"

  # license
  install -Dm644 COPYING \
    "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
