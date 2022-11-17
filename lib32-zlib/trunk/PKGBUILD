# Contributor: Ionut Biru <ibiru@archlinux.org>
# Contributor: Pierre Schmitz <pierre@archlinux.de>

_pkgbasename=zlib
pkgname=lib32-$_pkgbasename
pkgver=1.2.13
pkgrel=2
pkgdesc='Compression library implementing the deflate compression method found in gzip and PKZIP (32-bit)'
arch=('x86_64')
license=('custom')
url="https://www.zlib.net/"
depends=('lib32-glibc' "$_pkgbasename")
provides=('libz.so')
options=('debug')
source=("https://zlib.net/zlib-${pkgver}.tar.gz"{,.asc})
sha256sums=('b3a24de97a8fdbc835b9833169501030b8977031bcb54b3b3ac13740f846ab30'
            'SKIP')
validpgpkeys=('5ED46A6721D365587791E2AA783FCD8E58BCAFBA') # Mark Adler <madler@alumni.caltech.edu>

build() {
	export CC="gcc -m32"
	export CXX="g++ -m32"
	export PKG_CONFIG="i686-pc-linux-gnu-pkg-config"

	cd "${srcdir}"/zlib-$pkgver
	./configure \
		--prefix=/usr \
		--libdir=/usr/lib32
	make
}

check() {
	cd zlib-$pkgver
	make test
}

package() {
	cd zlib-$pkgver
	make install DESTDIR="${pkgdir}"

	rm -rf "${pkgdir}"/usr/{include,share,bin}
	mkdir -p "$pkgdir/usr/share/licenses"
	ln -s $_pkgbasename "$pkgdir/usr/share/licenses/$pkgname"
}
