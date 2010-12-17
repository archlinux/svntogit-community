# Contributor: Andrea Scarpino <andrea@archlinux.org>
# Contributor: Alexander Fehr <pizzapunk gmail com>
# Contributor: pressh <pressh at gmail dot com>
# Maintainer: Daniel J Griffiths <ghost1227@archlinux.us>

pkgname=kazehakase
pkgver=0.5.8
pkgrel=2
pkgdesc="GTK+ web browser that uses the Gecko rendering engine"
arch=('i686' 'x86_64')
url="http://kazehakase.sourceforge.jp/"
license=('GPL')
depends=('xulrunner>=1.9.2')
makedepends=('intltool')
options=('!libtool')
source=('kazehakase-0.5.8.tar.gz::http://sourceforge.jp/frs/redir.php?m=iij&f=%2Fkazehakase%2F43802%2Fkazehakase-0.5.8.tar.gz'
	kazehakase-rev3870-xul192-workaround.patch
	kazehakase-0.5.7-external-rev938-libegg-parallel_make.patch)
md5sums=('22d831982ebe010338907381caee8fdf'
         'd85665b5b8b56e0b9f405422494e3263'
         'b03ad7840b801ecaf66a83e5e2818015')

build() {
	cd ${srcdir}/${pkgname}-${pkgver}

	patch -Np0 -i ${srcdir}/kazehakase-rev3870-xul192-workaround.patch
	patch -Np0 -i ${srcdir}/kazehakase-0.5.7-external-rev938-libegg-parallel_make.patch

	./autogen.sh

	./configure --prefix=/usr \
	    --sysconfdir=/etc \
	    --with-gecko-engine=libxul \
	    --disable-gtkmozembed \
	    --with-ruby=no \
	    --with-rgettext=no

	  make
}

package() {
	cd ${srcdir}/${pkgname}-${pkgver}

	make DESTDIR=${pkgdir} install
}
