# Contributor: Thomas S Hatch <thatch45@gmail.com>
# Contributor: Jon Nordby <jononor@gmail.com>

pkgname=augeas
pkgver=1.14.0
pkgrel=1
pkgdesc="A configuration editing tool that parses config files and transforms them into a tree"
arch=('x86_64')
url="http://augeas.net"
license=('LGPL')
depends=('libxml2' 'gcc-libs')
validpgpkeys=('AED6E2A185EEB379F17476D2E012D07AD0E3CC30')
source=(https://github.com/hercules-team/augeas/releases/download/release-$pkgver/augeas-$pkgver.tar.gz)
sha512sums=('06ef6f735686ae09ec8733a3daf36f6838fa56e761dc6d89e5c44420ea2403a4649bec162b8e49b2c3fe32f0eced8413eba1f2c551103a43860bba823315f1ef')

build() {
  cd $pkgname-$pkgver
  ./configure --prefix=/usr
  make
}

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
