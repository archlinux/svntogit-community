# Maintainer: Jaroslav Lichtblau <svetlemodry@archlinux.org>

pkgname=vifm
pkgver=0.13
pkgrel=1
pkgdesc="A file manager with curses interface, which provides Vi[m]-like environment"
arch=('x86_64')
url="https://vifm.info/"
license=('GPL')
depends=('ncurses' 'desktop-file-utils')
makedepends=('perl')
changelog=$pkgname.changelog
source=(https://prdownloads.sourceforge.net/$pkgname/$pkgname-$pkgver.tar.bz2{,.asc})
validpgpkeys=('22349CDBE5227D2108A5667799DC5E4DB05F6BE2') # xaizek <xaizek@posteo.net>
sha256sums=('0d9293749a794076ade967ecdc47d141d85e450370594765391bdf1a9bd45075'
            'SKIP')

build() {
  cd "${srcdir}"/$pkgname-$pkgver

  CFLAGS+=' -fcommon' # https://wiki.gentoo.org/wiki/Gcc_10_porting_notes/fno_common

  ./configure --prefix=/usr --sysconfdir=/etc
  make
}

package() {
  cd "${srcdir}"/$pkgname-$pkgver

  make DESTDIR="${pkgdir}" install
}
