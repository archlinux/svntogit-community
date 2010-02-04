# Maintainer: Corrado Primier <bardo@aur.archlinux.org>
pkgname=libreplaygain
pkgver=453
pkgrel=1
pkgdesc="A library to adjust audio gain"
arch=('i686' 'x86_64')
url="http://www.musepack.net/index.php?pg=src"
license=('LGPL')
depends=('glibc')
makedepends=('cmake')
source=(http://files.musepack.net/source/${pkgname}_r${pkgver}.tar.gz)
md5sums=('1bde8f0319fd2a2b9921b2a2dfc47655')

build() {
  mkdir "${srcdir}/${pkgname}_r${pkgver}/build"
  cd "${srcdir}/${pkgname}_r${pkgver}/build"

  cmake -DCMAKE_INSTALL_PREFIX=/usr ..
  make DESTDIR="${pkgdir}/" install

  mkdir -p "${pkgdir}/usr/include/replaygain/"
  install -Dm644 ${srcdir}/${pkgname}_r${pkgver}/include/replaygain/* \
    ${pkgdir}/usr/include/replaygain/
}

# vim:set ts=2 sw=2 et:
