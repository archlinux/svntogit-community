# Contributor: Aurelien Foret <orelien@chez.com>
# Maintainer: Douglas Soares de Andrade <douglas@archlinux.org>

pkgname=patchutils
pkgver=0.4.2
pkgrel=2
pkgdesc="A small collection of programs that operate on patch files"
license=('GPL')
url="http://cyberelk.net/tim/patchutils/"
depends=('python3' 'pcre2')
makedepends=('xmlto')
arch=('x86_64')
source=("http://cyberelk.net/tim/data/patchutils/stable/$pkgname-$pkgver.tar.xz"{,.sig})
sha256sums=('8875b0965fe33de62b890f6cd793be7fafe41a4e552edbf641f1fed5ebbf45ed'
            'SKIP')
validpgpkeys=('4629AFE960EC20BEC12E3104B7C20D079491EA63') # Tim Waugh <tim@cyberelk.net>

build() {
  cd "${srcdir}"/${pkgname}-${pkgver}

  ./configure --prefix=/usr
  make
}

package() {
  cd "${srcdir}"/${pkgname}-${pkgver}

  make DESTDIR="${pkgdir}" install
}
