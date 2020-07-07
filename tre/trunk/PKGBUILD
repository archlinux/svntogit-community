# Maintainer: Lukas Fleischer <lfleischer@archlinux.org>
# Contributor: Stefan Husmann <stefan-husmann@t-online.de
# Contributor: Igor Galic<i.galic@gmail.com>

pkgname=tre
pkgver=0.8.0
pkgrel=6
arch=('x86_64')
pkgdesc="POSIX compliant regexp matching library. Includes agrep for approximate grepping."
url="https://laurikari.net/tre"
depends=('glibc')
license=('custom:BSD')
source=("https://laurikari.net/tre/$pkgname-$pkgver.tar.bz2")
md5sums=('b4d3232593dadf6746f4727bdda20b41')

build() {
	cd "$srcdir/$pkgname-$pkgver"
	./configure --prefix=/usr --enable-static 
	make 
}

package() {
	cd "$srcdir/$pkgname-$pkgver"

	make DESTDIR="$pkgdir" install 

	install -Dm644 "$srcdir/$pkgname-$pkgver/LICENSE" \
		"$pkgdir/usr/share/licenses/$pkgname/LICENSE"
	install -d "$pkgdir/usr/share/doc/$pkgname"

	cd doc
	for f in default.css tre-api.html tre-syntax.html; do
		install -Dm644 "$f" "$pkgdir/usr/share/doc/$pkgname/$f"
	done 
}
