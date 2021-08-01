# Maintainer: Jerome Leclanche <jerome@leclan.ch>
# Contributor: Isaac Dupree <antispam@idupree.com>

pkgname=sassc
pkgver=3.6.2
pkgrel=3
pkgdesc="C implementation of Sass CSS preprocessor."
arch=("x86_64")
url="https://sass-lang.com"
license=("MIT")
depends=("libsass")
source=("$pkgname-$pkgver.tar.gz::https://github.com/sass/$pkgname/archive/$pkgver.tar.gz")
sha256sums=("608dc9002b45a91d11ed59e352469ecc05e4f58fc1259fc9a9f5b8f0f8348a03")


build() {
	cd "$srcdir/$pkgname-$pkgver"

	autoreconf -i
	./configure --prefix=/usr
	make
}

package() {
	cd "$srcdir/$pkgname-$pkgver"

	make DESTDIR="$pkgdir/" install
	install -D -m644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
