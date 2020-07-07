# Maintainer: Balló György <ballogyor+arch at gmail dot com>
# Contributor: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: Ionut Biru <ibiru@archlinux.org>

pkgbase=gtksourceviewmm
pkgname=(gtksourceviewmm gtksourceviewmm-docs)
pkgver=3.18.0
pkgrel=5
epoch=1
pkgdesc='C++ bindings for the gtksourceview library'
arch=('x86_64')
url='https://gitlab.gnome.org/GNOME/gtksourceviewmm'
license=('LGPL')
depends=('gtkmm3' 'gtksourceview3')
makedepends=('gtkmm3-docs')
source=("https://download.gnome.org/sources/$pkgname/${pkgver:0:4}/$pkgname-$pkgver.tar.xz")
sha256sums=('51081ae3d37975dae33d3f6a40621d85cb68f4b36ae3835eec1513482aacfb39')

build() {
  cd $pkgbase-$pkgver
  ./configure --prefix=/usr
  sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool
  make
}

package_gtksourceviewmm() {
  cd $pkgbase-$pkgver
  make DESTDIR="$pkgdir" install doc_subdirs=
}

package_gtksourceviewmm-docs() {
  pkgdesc="Developer documentation for gtksourceviewmm"
  depends=(gtkmm3-docs)

  cd $pkgbase-$pkgver
  make -C docs DESTDIR="$pkgdir" install
}
