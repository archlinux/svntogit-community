# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: Daniel J Griffiths <ghost1227@archlinux.us>

pkgname=macchanger
pkgver=1.7.0
pkgrel=4
pkgdesc="A small utility to change your NIC's MAC address"
arch=('x86_64')
#url="https://ftp.gnu.org/gnu/macchanger"
url="https://www.gnu.org/software/macchanger"
license=('GPL')
depends=('glibc')
source=("$pkgname-$pkgver.tgz::https://github.com/alobbs/macchanger/archive/$pkgver.tar.gz")
md5sums=('ebd3c24360454b2684c39d89dcaabac8')

prepare() {
  cd "${srcdir}/${pkgname}-${pkgver}"
  # FS#59021
  sed -i 's|/dev/hwrng|/dev/random|' src/main.c
}

build() {
  cd "${srcdir}/${pkgname}-${pkgver}"
  ./autogen.sh
  ./configure --prefix=/usr \
              --mandir=/usr/share/man \
              --infodir=/usr/share/info
  make
}

package() {
  cd "${srcdir}/${pkgname}-${pkgver}"

  make DESTDIR="${pkgdir}" install
}
