# Contributor: Thomas Dziedzic < gostrc at gmail >
# Contributor: Bert Muennich <muennich at informatik.hu-berlin.de>
# Maintainer: Brad Fanella <bradfanella@archlinux.us>

pkgname=sxiv
pkgver=0.9
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
md5sums=('865f1e542669ad6d7932fcd4664fb481'
         '1dda85ff6bed4de337f8fb303075ed11'
	 '05c3801bf32c2861c3c7b37073664db3')

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
