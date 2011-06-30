# Maintainer: Thomas Dziedzic < gostrc at gmail >
# Contributor: Bert Muennich <muennich at informatik.hu-berlin.de>

pkgname=sxiv
pkgver=0.8.2
pkgrel=1
pkgdesc='simple x image viewer'
arch=('i686' 'x86_64')
license=('GPL2')
install=('sxiv.install')
url='https://github.com/muennich/sxiv'
depends=('libx11' 'xproto' 'imlib2')
source=("https://github.com/downloads/muennich/sxiv/sxiv-${pkgver}.tar.gz"
        'sxiv.desktop'
        'config.h')
md5sums=('6948b4c02f9458c4160c6e458228b85f'
         '1dda85ff6bed4de337f8fb303075ed11'
         '8018e9f2f63b155098428be9dbaf8b5c')

build() {
  cd sxiv-${pkgver}

  cp ${srcdir}/config.h .

  make
}

package() {
  cd sxiv-${pkgver}

  make PREFIX=${pkgdir}/usr install

  install -D -m644 ${srcdir}/sxiv.desktop \
    ${pkgdir}/usr/share/applications/sxiv.desktop
}
