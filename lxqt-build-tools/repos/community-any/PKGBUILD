# Maintainer: Chih-Hsuan Yen <yan12125@archlinux.org>
# Contributor: Jerome Leclanche <jerome@leclan.ch>

pkgname=lxqt-build-tools
pkgver=0.13.0
pkgrel=1
pkgdesc="Various packaging tools and scripts for LXQt applications"
arch=("any")
url="https://github.com/lxqt/$pkgname"
license=("BSD")
depends=("cmake" "qt5-tools" "git" "perl")
source=(
	"https://github.com/lxqt/$pkgname/releases/download/$pkgver/$pkgname-$pkgver.tar.xz"
	"https://github.com/lxqt/$pkgname/releases/download/$pkgver/$pkgname-$pkgver.tar.xz.asc"
)
sha256sums=('fd3c199d0d7c61f23040a45ead57cc9a4f888af5995371f6b0ce1fa902eb59ce'
            'SKIP')
validpgpkeys=(
	"19DFDF3A579BD509DBB572D8BE793007AD22DF7E"  # https://github.com/tsujan.gpg
)

build() {
	mkdir -p build
	cd build
	cmake "$srcdir/$pkgname-$pkgver" \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=None
	make
}

package() {
	cd build
	make DESTDIR="$pkgdir" install
	install -Dm644 ../$pkgname-$pkgver/BSD-3-Clause -t "$pkgdir/usr/share/licenses/$pkgname"
}
