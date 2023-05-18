# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor: Marco Cilloni <krnlpk@gmail.com>

pkgname=exfatprogs
pkgver=1.2.1
pkgrel=1
pkgdesc='exFAT filesystem userspace utilities for the Linux Kernel exfat driver'
arch=('x86_64')
url='https://github.com/exfatprogs/exfatprogs'
license=('GPL2')
depends=('glibc')
provides=('exfat-utils')
conflicts=('exfat-utils')
source=("https://github.com/exfatprogs/exfatprogs/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz")
b2sums=('6fc2bcb0bd9ac2ca57a7e1255d227c50c1fa9d9f683809d0af619ca64f9d19951c5b5a9d6a24ad013e0eb709420229f28537dc98cf929b4b1821a1e2faffb6d2')

prepare() {
  cd exfatprogs-${pkgver}
  ./autogen.sh
}

build() {
  cd exfatprogs-${pkgver}
  ./configure --prefix=/usr --sbindir=/usr/bin
  make
}

package() {
  cd exfatprogs-${pkgver}
  make DESTDIR="${pkgdir}" install
  install -Dm644 -t "${pkgdir}"/usr/share/man/man8 */*.8
}
