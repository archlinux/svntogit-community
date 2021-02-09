# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: Mateusz Herych <heniekk@gmail.com>
# Contributor: Bj?indeijer <bjorn@lindeijer.nl>

pkgname=enet
pkgver=1.3.17
pkgrel=1
pkgdesc='A relatively thin, simple and robust network communication layer on top of UDP'
arch=('x86_64')
url='http://enet.bespin.org/'
license=('custom')
depends=('glibc')
source=("http://enet.bespin.org/download/${pkgname}-${pkgver}.tar.gz")
sha512sums=('efa0cb093a6ca295e5012a4fdebc5ffd6516a66a967e97b386b72781b18ce4a118c9bf94e87adbbdcd0ed441e22c62a05c24ff39fd6b475919e8efe9ab4715e4')

build() {
  cd "${pkgname}-${pkgver}"
  ./configure --prefix=/usr
  make
}

package() {
  cd "${pkgname}-${pkgver}"
  make DESTDIR="${pkgdir}" install
  install -Dm644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
