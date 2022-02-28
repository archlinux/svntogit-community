# Maintainer: Massimiliano Torromeo <massimiliano.torromeo@gmail.com>
# Contributor: Andreas Wagner <Andreas dot Wagner at em dot uni-frankfurt dot de>

pkgname=oniguruma
pkgver=6.9.7.1
pkgrel=2
pkgdesc="a regular expressions library"
arch=('x86_64')
url="https://github.com/kkos/oniguruma"
license=('BSD')
options=('debug')
source=("https://github.com/kkos/oniguruma/releases/download/v$pkgver/onig-${pkgver/_/-}.tar.gz")
sha256sums=('6444204b9c34e6eb6c0b23021ce89a0370dad2b2f5c00cd44c342753e0b204d9')

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
