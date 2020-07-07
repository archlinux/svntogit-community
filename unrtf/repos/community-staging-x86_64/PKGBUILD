# Maintainer: Jaroslav Lichtblau <svetlemodry@archlinux.org>
# Contributor: Alexander Fehr <pizzapunk gmail com>
# Contributor: froggie <sullivanva@gmail.com>

pkgname=unrtf
pkgver=0.21.10
pkgrel=2
pkgdesc="Command-line program which converts RTF documents to other formats"
arch=('x86_64')
url="https://www.gnu.org/software/unrtf/unrtf.html"
license=('GPL3')
depends=('glibc')
changelog=$pkgname.changelog
source=(https://ftp.gnu.org/gnu/$pkgname/$pkgname-$pkgver.tar.gz{,.sig})
sha256sums=('b49f20211fa69fff97d42d6e782a62d7e2da670b064951f14bbff968c93734ae'
            'SKIP')
validpgpkeys=('46EA854F5FC5F5A0A9D2BFE89175BF0B3EC83090') # Dave Davey (lgf) <daved@windclimber.id.au>

build() {
  cd "${srcdir}"/$pkgname-$pkgver

  ./configure --prefix=/usr
  make
}

package() {
  cd "${srcdir}"/$pkgname-$pkgver

  make DESTDIR="${pkgdir}" install
}
