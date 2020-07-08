# Maintainer: Sven-Hendrik Haasr <svenstaro@gmail.com>
# Contributor: nl6720 <nl6720@gmail.com>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: d'Ronin <daronin@2600.com>

pkgname=judy
pkgver=1.0.5
pkgrel=7
arch=('x86_64')
pkgdesc='C library creating and accessing dynamic arrays'
depends=('glibc')
makedepends=('gcc')
license=('LGPL')
url='http://judy.sourceforge.net/'
source=("https://downloads.sourceforge.net/judy/Judy-${pkgver}.tar.gz")
sha512sums=('1a0d59b092c80d95270a3089cd25ee0ddad1d591101b03784e2e46dfc73bce445a7fb495b449043544a366c09b35b833556053bf3bf65dd00abbd786d26c6980')

build() {
  cd "${srcdir}/${pkgname}-${pkgver}"
  ./configure --prefix=/usr
  make -j1
}

check() {
  cd "${srcdir}/${pkgname}-${pkgver}"
  make check
}

package() {
  cd "${srcdir}/${pkgname}-${pkgver}"
  make DESTDIR="$pkgdir" install
}
