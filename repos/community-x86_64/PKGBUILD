# Contributor: Filipp "Scorp" Andjelo <scorp@mailueberfall.de>

pkgname=lxinput
pkgver=0.3.2
pkgrel=1
pkgdesc="A small program to configure keyboard and mouse for LXDE."
arch=('i686' 'x86_64')
url="http://lxde.org/"
license=('GPL')
depends=('gtk2>=2.12.0')
makedepends=('pkgconfig' 'intltool')
source=(http://downloads.sourceforge.net/sourceforge/lxde/${pkgname}-${pkgver}.tar.gz)
md5sums=('5bf563d04984ef2a147433f3bdda687b')

build() {
  cd ${srcdir}/${pkgname}-${pkgver}
  ./configure --prefix=/usr
  make
}

package() {
  cd ${srcdir}/${pkgname}-${pkgver}
  make DESTDIR=${pkgdir} install
}

