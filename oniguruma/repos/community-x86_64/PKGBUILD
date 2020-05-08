# Maintainer: Massimiliano Torromeo <massimiliano.torromeo@gmail.com>
# Contributor: Andreas Wagner <Andreas dot Wagner at em dot uni-frankfurt dot de>

pkgname=oniguruma
pkgver=6.9.5_rev1
pkgrel=1
pkgdesc="a regular expressions library"
arch=('x86_64')
url="https://github.com/kkos/oniguruma"
license=('BSD')
source=("https://github.com/kkos/oniguruma/releases/download/v$pkgver/onig-${pkgver/_/-}.tar.gz")
sha256sums=('d33c849d1672af227944878cefe0a8fcf26fc62bedba32aa517f2f63c314a99e')

build() {
	cd "$srcdir"/onig-${pkgver%_rev1}
	./configure --prefix=/usr --enable-posix-api
	make
}

package() {
	cd "$srcdir"/onig-${pkgver%_rev1}
	make DESTDIR="$pkgdir" install
	install -dm755 "$pkgdir"/usr/share/doc
	cp -r doc "$pkgdir"/usr/share/doc/$pkgname
	for licfile in COPYING INSTALL; do
		install -Dm644 $licfile "$pkgdir"/usr/share/licenses/$pkgname/$licfile
	done
}
