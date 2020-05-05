# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: Daniel J Griffiths <ghost1227@archlinux.us>

pkgname=macchanger
pkgver=1.7.0
pkgrel=5
pkgdesc="A small utility to change your NIC's MAC address"
arch=('x86_64')
#url="https://ftp.gnu.org/gnu/macchanger"
url="https://www.gnu.org/software/macchanger"
license=('GPL')
depends=('glibc')
source=("$pkgname-$pkgver.tgz::https://github.com/alobbs/macchanger/archive/$pkgver.tar.gz")
md5sums=('ebd3c24360454b2684c39d89dcaabac8')
sha256sums=('1d75c07a626321e07b48a5fe2dbefbdb98c3038bb8230923ba8d32bda5726e4f')
b2sums=('5dcd174152e77d342a49ac8d9aaa7bc4d8e0e940ddd0f78c0b4b5e8634b424a4e163d1d568238d169b3f962a9a7bc5e8a7caf4df3d1a949ae3aec75b715f696a')

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
