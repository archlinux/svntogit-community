# Maintainer: Massimiliano Torromeo <massimiliano.torromeo@gmail.com>
# Contributor: Andreas Wagner <Andreas dot Wagner at em dot uni-frankfurt dot de>

pkgname=oniguruma
pkgver=6.9.8
pkgrel=1
pkgdesc="a regular expressions library"
arch=('x86_64')
url="https://github.com/kkos/oniguruma"
license=('BSD')
source=("https://github.com/kkos/oniguruma/releases/download/v$pkgver/onig-${pkgver/_/-}.tar.gz")
sha256sums=('28cd62c1464623c7910565fb1ccaaa0104b2fe8b12bcd646e81f73b47535213e')

build() {
	cd "$srcdir"/onig-${pkgver%.1}
	./configure --prefix=/usr --enable-posix-api
	make
}

package() {
	cd "$srcdir"/onig-${pkgver%.1}
	make DESTDIR="$pkgdir" install
	install -dm755 "$pkgdir"/usr/share/doc
	cp -r doc "$pkgdir"/usr/share/doc/$pkgname
	for licfile in COPYING INSTALL; do
		install -Dm644 $licfile "$pkgdir"/usr/share/licenses/$pkgname/$licfile
	done
}
