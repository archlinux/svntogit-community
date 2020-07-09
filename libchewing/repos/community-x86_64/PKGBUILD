# Maintainer: Chih-Hsuan Yen <yan12125@archlinux.org>
# Contributor: Gaetan Bisson <bisson@archlinux.org>
# Contributor: whisky <archlinux.cle(at)gmail.com>
# Contributor: damir <damir@archlinux.org>

pkgname=libchewing
pkgver=0.5.1
pkgrel=4
pkgdesc='Intelligent Chinese phonetic input method'
url='http://chewing.im/'
arch=('x86_64')
license=('LGPL2.1')
depends=('sqlite')
optdepends=(
  'chewing-editor: view and modify libchewing user phrases database'
)
source=("https://github.com/chewing/${pkgname}/releases/download/v${pkgver}/${pkgname}-${pkgver}.tar.bz2")
sha256sums=('9708c63415fa6034435c0f38100e7d30d0e1bac927f67bec6dfeb3fef016172b')

build() {
  cd ${pkgname}-${pkgver}
  ./configure --prefix=/usr
  make
}

check() {
  cd ${pkgname}-${pkgver}
  # parallel testing is broken (https://github.com/chewing/libchewing/issues/293)
  make -j1 check
}

package() {
  cd ${pkgname}-${pkgver}
  make DESTDIR="${pkgdir}" install
}
