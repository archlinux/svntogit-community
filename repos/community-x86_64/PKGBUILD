# Maintainer: Jerome Leclanche <jerome@leclan.ch>
# Contributor: Isaac Dupree <antispam@idupree.com>

pkgname=libsass
pkgver=3.6.5
pkgrel=2
pkgdesc="C implementation of Sass CSS preprocessor (library)."
arch=("x86_64")
url="https://sass-lang.com/libsass"
license=("MIT")
source=("$pkgname-$pkgver.tar.gz::https://github.com/sass/$pkgname/archive/$pkgver.tar.gz")
sha256sums=("89d8f2c46ae2b1b826b58ce7dde966a176bac41975b82e84ad46b01a55080582")


build() {
	cd "$srcdir/$pkgname-$pkgver"

	export LIBSASS_VERSION="$pkgver"
	autoreconf -i
	./configure --prefix=/usr
	make
}

package() {
	cd "$srcdir/$pkgname-$pkgver"

	make DESTDIR="$pkgdir/" install
	install -D -m644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
