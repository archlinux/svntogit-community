# Maintainer: Balló György <ballogyor+arch at gmail dot com>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Angel Velasquez <angvp@archlinux.org> 
# Contributor: Geoffroy Carrier <geoffroy.carrier@koon.fr>

pkgname=gpicview
pkgver=0.2.5
pkgrel=8
pkgdesc='Lightweight image viewer'
arch=('x86_64')
url='https://www.lxde.org/'
license=('GPL2')
groups=('lxde')
depends=('gtk3')
makedepends=('intltool')
replaces=('gpicview-gtk3')
source=("https://downloads.sourceforge.net/lxde/$pkgname-$pkgver.tar.xz"
        'gpicview.appdata.xml'
        '0001-Fix-displaying-images-with-GTK3.patch')
sha256sums=('38466058e53702450e5899193c4b264339959b563dd5cd81f6f690de32d82942'
            'dab79b2be536005044cc5edcc4f47e9f407a5fcf3126110a1ef2ab65c873dbf7'
            'f597fa7d5e8537665ea7bdf7bfffebaa32046e8feb4866866bfb64c219d8ea6d')

prepare() {
  cd $pkgname-$pkgver

  # Fix displaying images with GTK3
  # https://sourceforge.net/p/lxde/patches/542/
  patch -Np1 -i ../0001-Fix-displaying-images-with-GTK3.patch

  # Apply only one main category
  sed -i '/^Categories=/ s/Utility;//' gpicview.desktop.in
}

build() {
  cd $pkgname-$pkgver
  ./configure --prefix=/usr --enable-gtk3
  make
}

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
  install -Dm644 ../$pkgname.appdata.xml "$pkgdir/usr/share/metainfo/$pkgname.appdata.xml"
}
