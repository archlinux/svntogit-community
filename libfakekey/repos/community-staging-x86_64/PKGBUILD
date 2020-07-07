# Maintainer: Lukas Fleischer <lfleischer@archlinux.org>
# Contributor: zoulnix <z[o]ulnix.borkedduck.c[o]m>

pkgname=libfakekey
pkgver=0.3
pkgrel=2
pkgdesc='X virtual keyboard library.'
arch=('x86_64')
url='https://www.yoctoproject.org/tools-resources/projects/matchbox'
license=('GPL')
depends=('libxtst')
source=("https://git.yoctoproject.org/cgit/cgit.cgi/$pkgname/snapshot/$pkgname-$pkgver.tar.gz")
md5sums=('32c4939ed9ec6c96f6b630fa5513687d')

build() {
  cd "${pkgname}-${pkgver}"

  ./autogen.sh
  ./configure --prefix=/usr --sysconfdir=/etc --localstatedir=/var --disable-static
  make AM_LDFLAGS=-lX11
}

package() {
  cd "${pkgname}-${pkgver}"
  make DESTDIR="${pkgdir}" install
}
