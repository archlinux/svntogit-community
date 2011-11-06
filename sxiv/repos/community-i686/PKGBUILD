# Maintainer: Bartłomiej Piotrowski <barthalion@gmail.com>
# Contributor: Thomas Dziedzic < gostrc at gmail >
# Contributor: Bert Muennich <muennich at informatik.hu-berlin.de>
# Contributor: Brad Fanella <bradfanella@archlinux.us>

pkgname=sxiv
pkgver=1.0
pkgrel=1
pkgdesc='simple x image viewer'
arch=('i686' 'x86_64')
license=('GPL2')
install=sxiv.install
url='https://github.com/muennich/sxiv'
depends=('libx11' 'xproto' 'imlib2' 'desktop-file-utils')
source=("https://github.com/downloads/muennich/sxiv/sxiv-${pkgver}.tar.gz"
        'sxiv.desktop'
	    'config.h')
md5sums=('c887e0af1e4d5a101b285a46d288c419'
         '1dda85ff6bed4de337f8fb303075ed11'
         '78c71ef924095d7d6fb75222047de0bd')

build() {
  	cd "sxiv-${pkgver}"

	cp "$srcdir/config.h" .
	make
}

package() {
  	cd "sxiv-${pkgver}"

  	make PREFIX="${pkgdir}/usr" install
	install -D -m644 ${srcdir}/sxiv.desktop \
    		${pkgdir}/usr/share/applications/sxiv.desktop
}
