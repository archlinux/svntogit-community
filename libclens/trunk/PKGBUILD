#Maintainer: Dan Ziemba <zman0900@gmail.com>

pkgname=libclens
pkgver=0.7.0
pkgrel=1
pkgdesc="Convenience library to aid in porting code from OpenBSD"
arch=(i686 x86_64)
url="https://opensource.conformal.com/wiki/clens"
license=(ISC)

source=(https://opensource.conformal.com/snapshots/clens/clens-$pkgver.tar.gz)
sha1sums=('71eb0011eef16f1e87131b5aba34d44db92b1145')

build() {
	cd "clens-$pkgver"
	mkdir -p obj
	make LOCALBASE=/usr
}

package() {
	cd "clens-$pkgver"
	make LOCALBASE=/usr DESTDIR="$pkgdir" install
}
