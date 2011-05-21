# Maintainer: Bert Muennich <muennich at informatik.hu-berlin.de>

pkgname=sxiv
pkgver=0.8.1
pkgrel=1
pkgdesc="simple x image viewer"
arch=(i686 x86_64)
license=('GPL2')
install=('sxiv.install')
url="https://github.com/muennich/sxiv"
depends=('libx11' 'xproto' 'imlib2')
source=("https://github.com/downloads/muennich/sxiv/$pkgname-$pkgver.tar.gz"
        "sxiv.desktop"
        "config.h")
md5sums=('23006a1900690d46c0ff126c76cdbd02'
         '0b6d43bd356aadc12537c010950e2272'
         '8018e9f2f63b155098428be9dbaf8b5c')

build() {
  cd "${srcdir}/${pkgname}-${pkgver}"
  cp "${srcdir}/config.h" .

  make
  make PREFIX="${pkgdir}/usr" install

  install -m644 -D $srcdir/sxiv.desktop $pkgdir/usr/share/applications/sxiv.desktop
}
